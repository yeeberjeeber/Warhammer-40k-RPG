#include <iostream>
#include "utility/types.h"
#include "enemy/tyranids/termagaunt.h"
using namespace std;

Termagaunt::Termagaunt() {

    // stats
    BaseHealth = 11;
    BaseArmor = 5;
    BaseStr = 5;
    BaseDex = 6;
    BaseIntel = 1;
    BaseSpd = 17;

    // exp given
    EXP = 50;
    weightage = 1;

    health = HP(BaseArmor, BaseHealth, BaseHealth);
    stats = StatBlock(BaseStr, BaseDex, BaseIntel, BaseSpd);

}

ui16 Termagaunt::onDeath() {
    cout << "The Termagaunt let out a shriek that died in its throat as it crumpled to the ground, its chitinous limbs twitching once before going still." << endl;
    return EXP;
}