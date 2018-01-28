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

#include "mwsoundpreset.h"
#include <QPainter>
#include <QDebug>

MWSoundPreset::MWSoundPreset(QObject *parent): MisuWidget(parent)
{
    PresetSound.volume=800;
    PresetSound.wave_type=qrand() % 4;
    PresetSound.attack=qrand() % 100;
    PresetSound.decay=qrand() % 700;
    PresetSound.sustain=qrand() % 1000;
    PresetSound.release=qrand() % 1000;
    PresetSound.filter_cutoff=qrand() % 1000;
    PresetSound.filter_resonance=qrand() % 100;
    PresetSound.mod_filter_cutoff=50;
    PresetSound.mod_filter_resonance=0;

}

MWSoundPreset::MWSoundPreset(float vol, int wav, int att, int dec, float sus, int rel, float cut, float res, float modcut, float modres, QObject *parent): MisuWidget(parent)
{
    PresetSound.volume=vol;
    PresetSound.wave_type=wav;
    PresetSound.attack=att;
    PresetSound.decay=dec;
    PresetSound.sustain=sus;
    PresetSound.release=rel;
    PresetSound.filter_cutoff=cut;
    PresetSound.filter_resonance=res;
    PresetSound.mod_filter_cutoff=modcut;
    PresetSound.mod_filter_resonance=modres;
}

int MWSoundPreset::wave()
{
    return PresetSound.wave_type;
}

int MWSoundPreset::attack()
{
    return PresetSound.attack;
}

int MWSoundPreset::decay()
{
    return PresetSound.decay;
}

float MWSoundPreset::sustain()
{
    return PresetSound.sustain;
}

int MWSoundPreset::release()
{
    return PresetSound.release;
}

float MWSoundPreset::cutoff()
{
    return PresetSound.filter_cutoff;
}

float MWSoundPreset::resonance()
{
    return PresetSound.filter_resonance;
}

float MWSoundPreset::mod_cutoff()
{
    return PresetSound.mod_filter_cutoff;
}

float MWSoundPreset::mod_resonance()
{
    return PresetSound.mod_filter_resonance;
}

float MWSoundPreset::volume()
{
    return PresetSound.volume;
}

void MWSoundPreset::onPressed()
{
    pressed++;
    if(overwrite) {
        PresetSound.volume=Sound.volume;
        PresetSound.wave_type=Sound.wave_type;
        PresetSound.attack=Sound.attack;
        PresetSound.decay=Sound.decay;
        PresetSound.sustain=Sound.sustain;
        PresetSound.release=Sound.release;
        PresetSound.filter_cutoff=Sound.filter_cutoff;
        PresetSound.filter_resonance=Sound.filter_resonance;
        PresetSound.mod_filter_cutoff=Sound.mod_filter_cutoff;
        PresetSound.mod_filter_resonance=Sound.mod_filter_resonance;

        emit presetChanged();
        emit selectedChanged();
    }
    else {
        emit setSound(&PresetSound);
    }
}

void MWSoundPreset::onPressAndHold()
{

}

void MWSoundPreset::onCanceled()
{

}

void MWSoundPreset::onReleased()
{
    pressed--;
}

void MWSoundPreset::initialSet()
{
    emit setSound(&PresetSound);
}

void MWSoundPreset::onSoundChanged()
{
    emit selectedChanged();
}

bool MWSoundPreset::isSelected() {
    if( PresetSound.volume==Sound.volume &&
        PresetSound.wave_type==Sound.wave_type &&
        PresetSound.attack==Sound.attack &&
        PresetSound.decay==Sound.decay &&
        PresetSound.sustain==Sound.sustain &&
        PresetSound.release==Sound.release &&
        PresetSound.filter_cutoff==Sound.filter_cutoff &&
        PresetSound.filter_resonance==Sound.filter_resonance &&
        PresetSound.mod_filter_cutoff==Sound.mod_filter_cutoff &&
        PresetSound.mod_filter_resonance==Sound.mod_filter_resonance
    ) return true;
    else return false;
}
