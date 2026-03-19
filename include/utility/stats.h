#pragma once
#include "types.h"

class StatBlock {
private:
    ui16 Strength;
    ui16 Dexterity;
    ui16 Intelligence;
    ui16 Speed;

    static const ui16 baseStr = 23;
    static const ui16 baseDex = 19;
    static const ui16 baseIntel = 17;
    static const ui16 baseSpd = 20;

public:
    StatBlock();
    StatBlock(ui16 str, ui16 dex, ui16 intel, ui16 spd);

    void gainStr(int str) { Strength += str; } // leaving this here for future events
    void gainDex(int dex) { Dexterity += dex; }
    void gainIntel(int intel) { Intelligence += intel; }
    void gainSpd(int spd) { Speed += spd; }

    ui16 getStr() { return Strength; }
    ui16 getDex() { return Dexterity; }
    ui16 getIntel() { return Intelligence; }
    ui16 getSpeed() { return Speed; }
};