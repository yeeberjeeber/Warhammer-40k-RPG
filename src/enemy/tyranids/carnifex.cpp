#include <iostream>
#include "utility/types.h"
#include "enemy/tyranids/carnifex.h"

Carnifex::Carnifex() {

    // stats
    BaseHealth = 50;
    BaseArmor = 20;
    BaseStr = 25;
    BaseDex = 17;
    BaseIntel = 20;
    BaseSpd = 15;

    // exp given
    EXP = 120;
    weightage = 2;

    health = HP(BaseArmor, BaseHealth, BaseHealth);
    stats = StatBlock(BaseStr, BaseDex, BaseIntel, BaseSpd);
}

ui16 Carnifex::onDeath() {
    cout << "The Carnifex crashed down like a falling fortress, shaking the ground beneath my boots as its massive armoured body finally gave out, the light fading from its alien eyes with one last rattling bellow." << endl;
    return EXP;
}