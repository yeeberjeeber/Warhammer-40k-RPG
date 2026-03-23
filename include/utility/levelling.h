#pragma once
#include "types.h"

class Levelling {

protected:
    ui16 CurrentLevel;
    ui64 CurrentEXP;
    ui64 MaxEXP;
    ui16 EXPCap;

    // hard caps
    static constexpr float EXPMult = 1.2f;
    static const ui16 EXPCapAt1 = 100;
    static const ui8 MaxLevel = 99;

    static const ui8 BaseLevel = 1;
    static const ui16 StartingEXP = 0;

    ui16 EXPBarCalc(const ui16 cLevel);

    bool checkLevelUp(const ui16 cEXP);

public:
    Levelling();

    Levelling(ui16 cLevel, ui64 cEXP);

    bool gainEXP(ui64 gainedEXP);

    // getters
    ui16 getCurrentLevel() { return CurrentLevel; }
    ui64 getCurrentEXP() { return CurrentEXP; }
    ui64 getMaxEXP();
    ui16 getEXPCap() { return EXPCap; }
};
