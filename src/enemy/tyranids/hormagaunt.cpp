#include <iostream>
#include "utility/types.h"
#include "enemy/tyranids/hormagaunt.h"
using namespace std;

Hormagaunt::Hormagaunt() : health(BaseArmor, BaseHealth, BaseHealth), 
                           stats(BaseStr, BaseDex, BaseIntel, BaseSpd) {};

void Hormagaunt::takeDamage(ui16 dmg) {
    health.takeDamage(dmg);
    cout << endl;
    cout << "Enemy took " << dmg << " damage!" << endl;
}

ui16 Hormagaunt::getAttackDamage() {
    return stats.calculateDamage(BaseStr, BaseDex);
}

bool Hormagaunt::isAlive() {
    return health.isAlive(health.getCurrentHP());
}

ui16 Hormagaunt::onDeath() {
    cout << "It screeched once — sharp, alien, and furious, before collapsing into stillness, its chitinous limbs twitching as the hive mind’s grip slipped into silence." << endl;
    return EXP;
}

void Hormagaunt::displayStats() {
    cout << "Health: " << BaseHealth << endl;
    cout << "Damage: " << getAttackDamage() << endl;
    cout << "Speed: " << BaseSpd << endl;
}