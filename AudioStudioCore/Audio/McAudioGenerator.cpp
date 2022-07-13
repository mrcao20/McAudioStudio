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
#include "McAudioGenerator.h"

#include <QAudioDevice>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QMediaDevices>
#include <QStandardPaths>
#include <QWaveDecoder>
#include <QtEndian>

QString McAudioGenerator::generateData()
{
    QAudioDevice device = QMediaDevices::defaultAudioOutput();
    QAudioFormat format = device.preferredFormat();

    QString path = QDir(QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).first())
                       .absoluteFilePath("test.wav");
    QFile file(path);
    qDebug() << "open:" << file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QWaveDecoder wav(&file, format);
    qDebug() << "open:" << wav.open(QIODevice::WriteOnly);

    QVector<McTone> tones;
    tones.append({293, 0.5});
    tones.append({349, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({466, 0.5});
    tones.append({523, 1});
    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({587, 1});
    tones.append({523, 0.5});
    tones.append({466, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({349, 1});
    tones.append({293, 2.5});

    tones.append({293, 0.5});
    tones.append({349, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({466, 0.5});
    tones.append({523, 1});
    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({587, 1});
    tones.append({523, 0.5});
    tones.append({466, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({349, 1});
    tones.append({349, 0.2});
    tones.append({392, 2.3});

    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({880, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({698, 0.5});
    tones.append({523, 0.5});
    tones.append({587, 1});
    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 0.5});
    tones.append({932, 0.5});
    tones.append({880, 0.5});
    tones.append({698, 1});
    tones.append({587, 2.5});

    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({880, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({698, 0.5});
    tones.append({523, 0.5});
    tones.append({587, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({349, 0.5});
    tones.append({349, 0.2});
    tones.append({392, 2.8});

    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({880, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({698, 0.5});
    tones.append({523, 0.5});
    tones.append({587, 1});
    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 0.5});
    tones.append({932, 0.5});
    tones.append({880, 0.5});
    tones.append({698, 1});
    tones.append({587, 2.5});

    tones.append({587, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({784, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({880, 0.5});
    tones.append({698, 0.5});
    tones.append({784, 1});
    tones.append({698, 0.5});
    tones.append({523, 0.5});
    tones.append({587, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({392, 0.5});
    tones.append({349, 0.5});
    tones.append({349, 0.2});
    tones.append({392, 2.8});

    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({587, 0.5});
    tones.append({523, 0.5});
    tones.append({392, 1});
    tones.append({349, 1});
    tones.append({349, 0.2});
    tones.append({392, 2.8});

    qint64 totalDurationUs = 0;
    for (auto tone : tones) {
        totalDurationUs += (tone.duration * 1000000);
    }
    const int channelBytes = format.bytesPerSample();
    const int sampleBytes = format.channelCount() * channelBytes;
    qint64 totalLength = format.bytesForDuration(totalDurationUs);

    Q_ASSERT(totalLength % sampleBytes == 0);
    Q_UNUSED(sampleBytes); // suppress warning in release builds

    qreal frontDuration = 0.1; //!< 起始音量到全音量所经历时间：s
    qreal normalDuration = 0.4; //!< 全音量持续时间：s
    qreal backDuration = 1.5; //!< 全音量到结束音量所经历时间：s

    QByteArray buffer(totalLength, 0);
    unsigned char *ptr = reinterpret_cast<unsigned char *>(buffer.data());
    qreal phase = 0.0;
    const qreal d = 2 * M_PI / format.sampleRate();
    for (auto tone : tones) {
        qint64 simples = format.sampleRate() * tone.duration;

        qint64 frontSimples = format.sampleRate() * frontDuration;
        qreal frontDelta = 0.2 / frontSimples;
        qint64 normalSimples = format.sampleRate() * normalDuration;
        qint64 backSimples = format.sampleRate() * backDuration;
        qreal backDelta = 0.8 / backSimples;

        qreal phaseStep = d * tone.freq;
        qreal volume = 0.8;
        for (int i = 0; i < simples; ++i) {
            const qreal x = qSin(phase) * volume;
            for (int i = 0; i < format.channelCount(); ++i) {
                switch (format.sampleFormat()) {
                case QAudioFormat::UInt8:
                    qToLittleEndian<quint8>(128 * volume + 127 * x, ptr);
                    break;
                case QAudioFormat::Int16:
                    qToLittleEndian<qint16>(x * 32767, ptr);
                    break;
                case QAudioFormat::Int32:
                    qToLittleEndian<qint32>(x * std::numeric_limits<qint32>::max(), ptr);
                    break;
                case QAudioFormat::Float:
                    qToLittleEndian<float>(x, ptr);
                    break;
                default:
                    break;
                }

                ptr += channelBytes;
            }

            phase += phaseStep;
            while (phase > 2 * M_PI) {
                phase -= 2 * M_PI;
            }

            if (frontSimples > 0) {
                volume += frontDelta;
                --frontSimples;
            } else if (normalSimples > 0) {
                --normalSimples;
            } else if (backSimples > 0) {
                volume -= backDelta;
                --backSimples;
            }
        }
    }
    wav.write(buffer);
    wav.close();

    return path;
}
