/*
 * MIT License
 *
 * Copyright (c) 2021 mrcao20
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "McSampler.h"

#include <QDebug>
#include <QtEndian>

#include "Envelope/IMcEnvelope.h"
#include "Tone/IMcToneGenerator.h"

MC_DECL_PRIVATE_DATA(McSampler)
QAudioFormat format;
QByteArray sampleData;
MC_DECL_PRIVATE_DATA_END

McSampler::McSampler(const QAudioFormat &format) noexcept
{
    MC_NEW_PRIVATE_DATA(McSampler);

    setFormat(format);
}

McSampler::~McSampler() {}

const QAudioFormat &McSampler::format() const noexcept
{
    return d->format;
}

void McSampler::setFormat(const QAudioFormat &newFormat) noexcept
{
    d->format = newFormat;
}

const QByteArray &McSampler::sampleData() const noexcept
{
    return d->sampleData;
}

void McSampler::sample(
    const McTone &tone, const IMcToneGeneratorPtr &generator, const IMcEnvelopePtr &envelope, qreal volume) noexcept
{
    if (volume == 11) { //! loudest
        volume = 1.0;
    } else if (volume < 0 || volume > 1) {
        qCritical("Invalid volume: must be within range 0.0 .. 1.0");
        return;
    }

    const int channelBytes = d->format.bytesPerSample();
    const int sampleBytes = d->format.channelCount() * channelBytes;
    qint64 totalLength = d->format.bytesForDuration(tone.duration * 1000000);

    Q_ASSERT(sampleBytes != 0 && totalLength % sampleBytes == 0);
    Q_UNUSED(sampleBytes); // suppress warning in release builds

    QByteArray buffer(totalLength, 0);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(buffer.data());

    int simples = d->format.sampleRate() * tone.duration;
    for (int i = 0; i < simples; i++) {
        double timeIndexSeconds = i * 1.0 / d->format.sampleRate();
        double sample = generator->generate(tone, timeIndexSeconds);

        // apply envelope
        sample = sample * envelope->getAmplitude(timeIndexSeconds);

        // apply volume
        sample = sample * volume;

        for (int i = 0; i < d->format.channelCount(); ++i) {
            switch (d->format.sampleFormat()) {
            case QAudioFormat::UInt8:
                qToLittleEndian<quint8>((sample + 1.0) / 2.0 * 255, ptr);
                break;
            case QAudioFormat::Int16:
                qToLittleEndian<qint16>(sample * 32767, ptr);
                break;
            case QAudioFormat::Int32:
                qToLittleEndian<qint32>(sample * std::numeric_limits<qint32>::max(), ptr);
                break;
            case QAudioFormat::Float:
                qToLittleEndian<float>(sample, ptr);
                break;
            default:
                break;
            }

            ptr += channelBytes;
        }
    }
    d->sampleData.append(std::move(buffer));
}
