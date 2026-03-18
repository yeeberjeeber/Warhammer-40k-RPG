#pragma once
#include "types.h"

class Levelling {

protected:
    ui8 CurrentLevel;
    ui8 MaxLevel;
    ui16 CurrentEXP;
    ui16 MaxEXP;
    ui16 EXPCap;

    // hard caps
    static const ui8 EXPMult = 2;
    static const ui16 EXPCapAt1 = 100;
    static const ui8 MaxLevel = 99;

    ui16 EXPBarCalc(const ui8& cLevel) {}

    void checkLevelUp(const ui16& cEXP, ui8& cLevel) {}

public:
    Levelling();

    Levelling(ui8 cLevel, ui16 cEXP) {}

    void gainEXP(ui16& gainedEXP, ui8& cLevel) {}

    ui8 getCurrentLevel() { return CurrentLevel; }
    ui16 getCurrentEXP() { return CurrentEXP; }
    ui16 getMaxEXP() { return MaxEXP; }

};
