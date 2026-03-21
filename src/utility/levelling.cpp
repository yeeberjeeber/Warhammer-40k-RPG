#include <iostream>
#include "utility/levelling.h"
#include "utility/types.h"
using namespace std;

Levelling::Levelling() : CurrentLevel(BaseLevel), CurrentEXP(StartingEXP), MaxEXP(EXPBarCalc(BaseLevel)) {}; 

Levelling::Levelling(ui16 cLevel, ui16 cEXP) : CurrentLevel(cLevel), CurrentEXP(cEXP) {}

void Levelling::gainEXP(ui16 gainedEXP) {
    if(CurrentLevel == MaxLevel) return;         // check if we hit max level

    CurrentEXP += gainedEXP;
    checkLevelUp(CurrentEXP);

    EXPBarCalc(CurrentLevel);
    cout << "Next EXP Milestone: " << EXPBarCalc(CurrentLevel) << endl;
}

ui16 Levelling::EXPBarCalc(const ui16 cLevel) {  // EXPBarCalc promises to not change cLevel value
    EXPCap = EXPCapAt1 * (1 << (cLevel - 1));    // bit shifting, representing 2 to the pow of (cLevel - 1)
    return EXPCap;
}

void Levelling::checkLevelUp(const ui16 cEXP) {
    cout << cEXP << " EXP gained." << endl;

    if (cEXP > EXPCap) {                         // checking if current EXP exceeds the cap for the level
        CurrentLevel++;
        // Stat Spread per level
        
        cout << "Leveled up! The Emperor's favour shines upon thee." << endl;
        cout << "Current Level: " << CurrentLevel << endl;
        cout << "Current EXP: " << CurrentEXP << endl;
    }
}