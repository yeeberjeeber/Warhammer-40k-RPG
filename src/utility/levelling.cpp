#include <iostream>
#include "utility/levelling.h"
#include "utility/types.h"
using namespace std;

Levelling::Levelling() : CurrentLevel(1), CurrentEXP(0) {};

Levelling::Levelling(ui8 cLevel, ui16 cEXP) : CurrentLevel(cLevel), CurrentEXP(cEXP) {}

void Levelling::gainEXP(ui16& gainedEXP, ui8& cLevel) {
    if(cLevel == MaxLevel) return;         // check if we hit max level

    CurrentEXP += gainedEXP;
    if(CurrentEXP > EXPBarCalc(cLevel)) {  // EXPBarCalc here promises to not change cLevel value
        cLevel++;                          // checking if current EXP exceeds the cap for the level
        cout << "Leveled up! The Emperor's favour shines upon thee." << endl;
        cout << "Current Level: " << cLevel << endl;
        cout << "Current EXP: " << CurrentEXP << endl;
    }
    ui16 newEXPCap = EXPBarCalc(cLevel);
    cout << "Next EXP Milestone: " << newEXPCap << endl;
}

ui16 Levelling::EXPBarCalc(const ui8& cLevel) {
    EXPCap = EXPCapAt1 * (1 << (cLevel - 1)); // bit shifting, representing 2 to the pow of (cLevel - 1)
    return EXPCap;
}

void Levelling::checkLevelUp(const ui16& cEXP, ui8& cLevel) {
    if (cEXP > EXPCap) cLevel + 1;
}