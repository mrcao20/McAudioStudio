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
#include "McViolinGenerator.h"

// Violin sound https://meettechniek.info/additional/additive-synthesis.html
qreal McViolinGenerator::generate(const McTone &tone, qreal timeIndexSeconds) noexcept
{
    qreal amplitude = 0.49;

    qreal harmonic1PeriodSeconds = 1.0 / tone.freq;
    qreal harmonic1Radians = timeIndexSeconds / harmonic1PeriodSeconds * (2 * M_PI);
    qreal harmonic1Amplitude = 0.995;

    qreal harmonic2PeriodSeconds = 1.0 / (tone.freq * 2);
    qreal harmonic2Radians = timeIndexSeconds / harmonic2PeriodSeconds * (2 * M_PI);
    qreal harmonic2Amplitude = 0.940;

    qreal harmonic3PeriodSeconds = 1.0 / (tone.freq * 3);
    qreal harmonic3Radians = timeIndexSeconds / harmonic3PeriodSeconds * (2 * M_PI);
    qreal harmonic3Amplitude = 0.425;

    qreal harmonic4PeriodSeconds = 1.0 / (tone.freq * 4);
    qreal harmonic4Radians = timeIndexSeconds / harmonic4PeriodSeconds * (2 * M_PI);
    qreal harmonic4Amplitude = 0.480;

    qreal harmonic6PeriodSeconds = 1.0 / (tone.freq * 6);
    Q_UNUSED(harmonic6PeriodSeconds)
    qreal harmonic6Radians = timeIndexSeconds / harmonic4PeriodSeconds * (2 * M_PI);
    qreal harmonic6Amplitude = 0.365;

    qreal harmonic7PeriodSeconds = 1.0 / (tone.freq * 7);
    qreal harmonic7Radians = timeIndexSeconds / harmonic7PeriodSeconds * (2 * M_PI);
    Q_UNUSED(harmonic7Radians)
    qreal harmonic7Amplitude = 0.040;

    qreal harmonic8PeriodSeconds = 1.0 / (tone.freq * 8);
    qreal harmonic8Radians = timeIndexSeconds / harmonic8PeriodSeconds * (2 * M_PI);
    qreal harmonic8Amplitude = 0.085;

    qreal harmonic10PeriodSeconds = 1.0 / (tone.freq * 10);
    qreal harmonic10Radians = timeIndexSeconds / harmonic10PeriodSeconds * (2 * M_PI);
    qreal harmonic10Amplitude = 0.090;

    qreal result = amplitude
                   * (harmonic1Amplitude * sin(harmonic1Radians) + harmonic2Amplitude * cos(harmonic2Radians)
                       + harmonic3Amplitude * sin(harmonic3Radians) + harmonic4Amplitude * cos(harmonic4Radians)
                       + harmonic6Amplitude * cos(harmonic6Radians) + harmonic7Amplitude * sin(harmonic6Radians)
                       + harmonic8Amplitude * cos(harmonic8Radians) + harmonic10Amplitude * cos(harmonic10Radians));

    return result;
}
