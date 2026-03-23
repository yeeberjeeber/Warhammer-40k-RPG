#include <iostream>
#include "enemy/enemy.h"
#include "utility/stats.h"
#include "utility/hp.h"
#include "utility/stats.h"

void Enemy::takeDamage(ui16 dmg) {
    health.takeDamage(dmg);
    cout << endl;
    cout << "Enemy took " << dmg << " damage!" << endl;
}

ui16 Enemy::getAttackDamage() {
    return stats.calculateDamage(BaseStr, BaseDex);
}

bool Enemy::isAlive() {
    return health.isAlive(health.getCurrentHP());
}

void Enemy::displayStats() {
    cout << "Health: " << BaseHealth << endl;
    cout << "Damage: " << getAttackDamage() << endl;
    cout << "Speed: " << BaseSpd << endl;
}