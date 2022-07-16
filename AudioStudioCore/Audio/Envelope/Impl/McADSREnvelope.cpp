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
#include "McADSREnvelope.h"

#include <QDebug>

MC_DECL_PRIVATE_DATA(McADSREnvelope)
qreal attackDurationSeconds;
qreal attackAmplitude;
qreal decayDurationSeconds;
qreal sustainDurationSeconds;
qreal sustainAmplitude;
qreal releaseDurationSeconds;
qreal releaseAmplitude;
MC_DECL_PRIVATE_DATA_END

McADSREnvelope::McADSREnvelope() noexcept
{
    MC_NEW_PRIVATE_DATA(McADSREnvelope);
}

McADSREnvelope::McADSREnvelope(qreal durationSeconds) noexcept
    : McADSREnvelope()
{
    change(durationSeconds);
}

void McADSREnvelope::change(qreal durationSeconds) noexcept
{
    if (durationSeconds <= 0.0) {
        qCritical("Invalid value for durationSeconds: must be positive non-zero value");
        return;
    }

    d->attackAmplitude = 1.0;
    d->attackDurationSeconds = durationSeconds * 0.1;

    //! decay amplitude range is given by attack and sustain
    d->decayDurationSeconds = durationSeconds * 0.1;

    d->sustainAmplitude = 0.7;
    d->sustainDurationSeconds = durationSeconds * 0.7;

    d->releaseAmplitude = 0.0;
    d->releaseDurationSeconds = durationSeconds * 0.1;
}

qreal McADSREnvelope::getAmplitude(qreal timeIndexSeconds) noexcept
{
    qreal result;

    if (timeIndexSeconds < d->attackDurationSeconds) {
        //! linearly increasing
        result = d->attackAmplitude / d->attackDurationSeconds * timeIndexSeconds;
    } else if (timeIndexSeconds < d->attackDurationSeconds + d->decayDurationSeconds) {
        qreal relativeTimeIndexSeconds = timeIndexSeconds - d->attackDurationSeconds;
        qreal relativeAmplitude = d->attackAmplitude - d->sustainAmplitude;

        //! linearly decreasing
        result = d->attackAmplitude - (relativeAmplitude / d->decayDurationSeconds * relativeTimeIndexSeconds);
    } else if (timeIndexSeconds < d->attackDurationSeconds + d->decayDurationSeconds + d->sustainDurationSeconds) {
        qreal relativeTimeIndexSeconds = timeIndexSeconds - d->attackDurationSeconds - d->decayDurationSeconds;
        Q_UNUSED(relativeTimeIndexSeconds)

        //! keep at same level
        result = d->sustainAmplitude;
    } else {
        qreal relativeTimeIndexSeconds = timeIndexSeconds - d->attackDurationSeconds - d->decayDurationSeconds
                                         - d->sustainDurationSeconds;

        //! linearly decreasing
        result = d->sustainAmplitude - (d->sustainAmplitude / d->releaseDurationSeconds * relativeTimeIndexSeconds);
    }

    return result;
}
