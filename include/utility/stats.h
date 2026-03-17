#pragma once
#include "types.h"

class StatBlock {
private:
    ui8 Strength;
    ui8 Dexterity;
    ui8 Intelligence;
    ui8 Speed;

public:
    StatBlock();
    StatBlock(ui8 str, ui8 dex, ui8 intel, ui8 spd);

    void gainStr() {}; // leaving this here for future events
    void gainDex() {};
    void gainIntel() {};
    void gainSpd() {};

    ui8 getStr() { return Strength; }
    ui8 getDex() { return Dexterity; }
    ui8 getIntel() { return Intelligence; }
    ui8 getSpeed() { return Speed; }
};