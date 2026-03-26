#include <iostream>
#include "utility/types.h"
#include "enemy/tyranids/carnifex.h"

Carnifex::Carnifex() {
    Name = "Carnifex";

    // stats
    BaseHealth = 50;
    BaseArmor = 20;
    BaseStr = 25;
    BaseDex = 17;
    BaseIntel = 20;
    BaseSpd = 15;
    MinLevel = 1;

    // exp given
    EXP = 120;
    weightage = 2;

    health = HP(BaseArmor, BaseHealth, BaseHealth);
    stats = StatBlock(BaseStr, BaseDex, BaseIntel, BaseSpd);
}