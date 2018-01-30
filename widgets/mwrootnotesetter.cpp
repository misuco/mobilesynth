﻿/*
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

#include "mwrootnotesetter.h"
#include "comm/senderdebug.h"
#include <QDebug>

MWRootNoteSetter::MWRootNoteSetter(Pitch * pitch, QObject *parent) : MisuWidget(parent)
{
    //qDebug() << "MWrootNoteSetter::MWrootNoteSetter " << pitch->pitch << " pitch basenote " << pitch->basenote;
    _out=new SenderDebug();
    _pitch=pitch;
    _freq=new FreqTriple(_pitch);
    _freq->setOct(4);
    _freq->setRootNote(_pitch);
    //qDebug() << "f: " << f->getFreq() << " " << f->getPitch() << " " << f->getHue();
    _vId=0;
    _pressed=0;
    _selected=false;
    calcText();
}

MWRootNoteSetter::~MWRootNoteSetter()
{
    _freq->deleteLater();
}

void MWRootNoteSetter::setOctMid(int o)
{
    _freq->setOct(o);
    calcText();
}

void MWRootNoteSetter::pitchChange()
{
    //qDebug() << "MWrootNoteSetter::pitchChange "  << f->getPitch();
    _freq->pitchChange();
    calcText();
}

void MWRootNoteSetter::onSetRootNote(Pitch * pitch)
{
    if(pitch == _pitch) {
        if(!_selected) {
            _selected = true;
            emit selectedChanged();
        }
    } else {
        if(_selected) {
            _selected = false;
            emit selectedChanged();
        }
    }
}

void MWRootNoteSetter::onScaleSet(MWScale * scale)
{
    //qDebug() << "MWrootNoteSetter::onScaleSet " << scale->basenote << " " << p->basenote;
    if(scale->rootNote==_pitch->getRootNote()) {
        if(!_selected) {
            _selected = true;
            emit selectedChanged();
        }
    } else {
        if(_selected) {
            _selected = false;
            emit selectedChanged();
        }
    }
}

void MWRootNoteSetter::onSymbolsChanged()
{
    calcText();
}

void MWRootNoteSetter::calcText()
{
    _text1 = _freq->getRootNoteString(noteSymbols);

    if(showFreqs) {
        _text2.sprintf("%5.1f",_freq->getFreq());
    } else {
        _text2="";
    }

    emit textChanged();
}

void MWRootNoteSetter::setOut(ISender *value)
{
    _out = value;
}

int MWRootNoteSetter::pitchId()
{
    return _pitch->getRootNote();
}

void MWRootNoteSetter::onPressed()
{
    _vId=_out->noteOn(channel,_freq->getFreq(),_freq->getMidinote(),_freq->getPitch(),127);
    emit setRootNote(_pitch);
    emit selectedChanged();
    _pressed++;
}

void MWRootNoteSetter::onReleased()
{
    _out->noteOff(_vId);
    _pressed--;
    calcText();
}

QObject *MWRootNoteSetter::pitch()
{
    return _pitch;
}

