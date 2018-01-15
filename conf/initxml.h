#ifndef INITXML_H
#define INITXML_H

#include <QByteArray>

const char * data = R"ESCAPE_SEQ(<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE misuco>
<misuco version="2.0">
<scale basenote="0" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<scale basenote="1" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<scale basenote="2" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<scale basenote="3" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<scale basenote="4" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<scale basenote="5" baseoct="4" topoct="5" b0="1" b1="0" b2="1" b3="1" b4="1" b5="0" b6="1" b7="1" b8="0" b9="0" b10="1"/>
<sound wave="1" attack="8" decay="91" sustain="939.000000" release="761" cutoff="43.000000" resonance="30.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<sound wave="1" attack="20" decay="467" sustain="750.000000" release="693" cutoff="643.000000" resonance="6.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<sound wave="3" attack="76" decay="233" sustain="931.000000" release="670" cutoff="798.000000" resonance="98.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<sound wave="1" attack="35" decay="348" sustain="63.000000" release="941" cutoff="116.000000" resonance="75.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<sound wave="0" attack="17" decay="106" sustain="187.000000" release="929" cutoff="731.000000" resonance="76.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<sound wave="1" attack="92" decay="179" sustain="629.000000" release="224" cutoff="725.000000" resonance="68.000000" mod_cutoff="50.000000" mod_resonance="0.000000" volume="800.000000"/>
<microtune t0="-1" t1="0" t2="0" t3="0" t4="0" t5="0" t6="0" t7="0" t8="0" t9="0" t10="0" t11="0"/>
<microtune t0="-10" t1="0" t2="0" t3="0" t4="0" t5="0" t6="0" t7="0" t8="0" t9="0" t10="0" t11="0"/>
<microtune t0="-50" t1="0" t2="0" t3="0" t4="0" t5="0" t6="0" t7="0" t8="0" t9="0" t10="0" t11="0"/>
<microtune t0="20" t1="0" t2="0" t3="0" t4="0" t5="0" t6="0" t7="0" t8="0" t9="0" t10="0" t11="0"/>
<microtune t0="40" t1="0" t2="0" t3="0" t4="0" t5="0" t6="0" t7="0" t8="0" t9="0" t10="0" t11="0"/>
<microtune t0="34" t1="0" t2="-20" t3="0" t4="41" t5="0" t6="-25" t7="0" t8="33" t9="0" t10="-15" t11="0"/>
<setup pitchTopRange="0" pitchBottomRange="2" pitchHorizontal="0" channel="5" sendCC1="0" bwmode="1" mobileSynth="1" pureData="0" reaktor="0" superCollider="0" holdMode="0" noteSymbols="1" showFreqs="1" showH0="1" showH1="0" showH2="0" showM0="0" showM1="1" showM2="0" showM3="0"/>
</misuco>
)ESCAPE_SEQ";

QByteArray initXml(data);

#endif // INITXML_H
