#include <iostream>
#include "utility/stats.h"
#include "utility/types.h"
using namespace std;

 StatBlock::StatBlock() : Strength(), Dexterity(), Intelligence(), Speed() {};

 StatBlock::StatBlock(ui16 str, ui16 dex, ui16 intel, ui16 spd) : Strength(str), Dexterity(dex), Intelligence(intel), Speed(spd) {};

 ui16 StatBlock::calculateDamage(ui8 str, ui8 dex) {
    ui16 dmg = (str * 1.5) + (dex * 0.5);
    return dmg;
 }