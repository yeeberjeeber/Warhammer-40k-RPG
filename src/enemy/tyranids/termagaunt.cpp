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
    cout << "It screeched once — sharp, alien, and furious, before collapsing into stillness, its chitinous limbs twitching as the hive mind’s grip slipped into silence." << endl;
    return EXP;
}