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
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PITCH_H
#define PITCH_H

#include <QObject>
#include "color.h"

class Pitch : public QObject, public Color
{
    Q_OBJECT

public:
    explicit Pitch(QObject *parent = 0);

    void setBasenote(int value);

    int getHue() const override;
    int getBW() const;

//protected:
    int pitch;
    int basenote;
    int color;

signals:
    void change();

public slots:
    void setPitch(int value);

private:
    void calcColor();
};

#endif // PITCH_H
