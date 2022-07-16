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

#include "Envelope/Impl/McADSREnvelope.h"
#include "McSampler.h"
#include "Tone/Impl/McViolinGenerator.h"

QByteArray McAudioGenerator::generateData(const QAudioFormat &format) noexcept
{
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

    auto pureTone = McViolinGeneratorPtr::create();
    auto adsrEnvelope = McADSREnvelopePtr::create();
    auto sampler = McSamplerPtr::create(format);
    for (auto tone : tones) {
        adsrEnvelope->change(tone.duration);
        sampler->sample(tone, pureTone, adsrEnvelope, 1.0);
    }

    return sampler->sampleData();
}
