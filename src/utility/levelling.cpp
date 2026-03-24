#include <iostream>
#include "utility/levelling.h"
#include "utility/types.h"
#include <cmath>
using namespace std;

Levelling::Levelling() : CurrentLevel(BaseLevel), CurrentEXP(StartingEXP), MaxEXP(EXPBarCalc(BaseLevel)) {}; 

Levelling::Levelling(ui16 cLevel, ui64 cEXP) : CurrentLevel(cLevel), CurrentEXP(cEXP) {}

bool Levelling::gainEXP(ui64 gainedEXP) {
    if(CurrentLevel == MaxLevel) {
        cout << "Max level reached." << endl;
        return false;         // check if we hit max level
    }

    CurrentEXP += gainedEXP;
    bool levelled = checkLevelUp(CurrentEXP);

    if (levelled) {
        EXPBarCalc(CurrentLevel);
        cout << "Next EXP Milestone: " << EXPBarCalc(CurrentLevel) << endl;
    }

    return levelled;
}

ui16 Levelling::EXPBarCalc(const ui16 cLevel) {  // EXPBarCalc promises to not change cLevel value
    EXPCap = EXPCapAt1 * pow(EXPMult, cLevel - 1);    // bit shifting, representing 2 to the pow of (cLevel - 1)
    return EXPCap;
}

ui64 Levelling::getMaxEXP() {
    MaxEXP = EXPCapAt1 * pow(EXPMult, 99 - 1);
    return MaxEXP;
}

bool Levelling::checkLevelUp(const ui16 cEXP) {
    cout << endl;
    cout << cEXP << " EXP gained." << endl;

    if (cEXP >= EXPCap) {                         // checking if current EXP exceeds the cap for the level
        CurrentLevel++;
        cout << "Leveled up! The Emperor's favour shines upon thee." << endl;
        cout << "Current Level: " << CurrentLevel << endl;
        cout << "Current EXP: " << CurrentEXP << endl;
        return true;
    }

    return false;
}