#pragma once
#include "types.h"

class Levelling {

protected:
    ui16 CurrentLevel;
    ui16 CurrentEXP;
    ui16 MaxEXP;
    ui16 EXPCap;

    // hard caps
    static const ui16 EXPMult = 2;
    static const ui16 EXPCapAt1 = 100;
    static const ui16 MaxLevel = 99;

    static const ui16 BaseLevel = 1;
    static const ui16 StartingEXP = 0;

    ui16 EXPBarCalc(const ui16 cLevel);

    void checkLevelUp(const ui16 cEXP);

public:
    Levelling();

    Levelling(ui16 cLevel, ui16 cEXP);

    void gainEXP(ui16 gainedEXP);

    // getters
    ui16 getCurrentLevel() { return CurrentLevel; }
    ui16 getCurrentEXP() { return CurrentEXP; }
    ui16 getMaxEXP() { return MaxEXP; }

};
