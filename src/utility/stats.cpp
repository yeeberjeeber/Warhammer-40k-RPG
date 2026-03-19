#include <iostream>
#include "utility/stats.h"
#include "utility/types.h"
using namespace std;

 StatBlock::StatBlock() : Strength(baseStr), Dexterity(baseDex), Intelligence(baseIntel), Speed(baseSpd) {};

 StatBlock::StatBlock(ui16 str, ui16 dex, ui16 intel, ui16 spd) : Strength(str), Dexterity(dex), Intelligence(intel), Speed(spd) {};
