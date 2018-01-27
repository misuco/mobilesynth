/*
 * Copyright (c) 2018 by misuco.org, Claudio Zopfi, Zurich, Switzerland, c@misuco.org
 *
 * This file is part of MISUCO2.
 *
 * MISUCO2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MISUCO2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MISUCO2.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <QDebug>
#include "pitch.h"
#include "widgets/misuwidget.h"

Pitch::Pitch(int rootNote, QObject *parent) : QObject(parent), _rootNote(rootNote), _pitch(0)
{
    calcColor();
}

float Pitch::getHue() const
{
    return _color;
}

int Pitch::getBW() const
{
    bool white = true;
    int bn = _rootNote;
    if(bn == 1 || bn == 3 || bn == 6 || bn == 8 || bn == 10 ) white = false;
    return white;
}

int Pitch::getRootNote()
{
    return _rootNote;
}

int Pitch::getPitch()
{
    return _pitch;
}

void Pitch::calcColor()
{
    _color = (float)_rootNote / 12 + (float)_pitch / 2400;
    if(_color>1) _color -=1;
    if(_color<0) _color +=1;

    if(MisuWidget::bwmode) {
        if(getBW()) {
            _color0 = MisuWidget::wkeycolor;
            _color1 = MisuWidget::hlwkeycolor;
        } else {
            _color0 = MisuWidget::bkeycolor;
            _color1 = MisuWidget::hlbkeycolor;
        }
    } else {
        _color0 = QColor::fromHslF(_color,MisuWidget::sOff,MisuWidget::lOff);
        _color1 = QColor::fromHslF(_color,MisuWidget::sOn,MisuWidget::lOn);
    }

    emit colorChanged();
    emit pitchChanged();
}

void Pitch::setPitch(int value)
{
    _pitch = value;
    calcColor();
}
