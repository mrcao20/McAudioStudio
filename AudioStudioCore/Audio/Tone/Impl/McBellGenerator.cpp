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
#include "McBellGenerator.h"

MC_DECL_PRIVATE_DATA(McBellGenerator)
qreal fm_Hz;
int I0;
qreal tau;
qreal theta_m;
qreal theta_c;
MC_DECL_PRIVATE_DATA_END

McBellGenerator::McBellGenerator(qreal fm_Hz, int I0, qreal tau) noexcept
{
    MC_NEW_PRIVATE_DATA(McBellGenerator);

    d->fm_Hz = fm_Hz;
    d->I0 = I0;
    d->tau = tau;
    d->theta_m = -M_PI / 2;
    d->theta_c = -M_PI / 2;
}

//! Bells 1-6, https://web.eecs.utk.edu/~qi/ece505/project/proj1.pdf
qreal McBellGenerator::generate(const McTone &tone, qreal timeIndexSeconds) noexcept
{
    qreal fc_Hz = tone.freq;
    qreal At = exp(-timeIndexSeconds / d->tau);
    qreal It = d->I0 * exp(-timeIndexSeconds / d->tau);
    qreal result = At
                   * cos(2 * M_PI * fc_Hz * timeIndexSeconds
                         + It * cos(2 * M_PI * d->fm_Hz * timeIndexSeconds + d->theta_m) + d->theta_c);

    return result;
}
