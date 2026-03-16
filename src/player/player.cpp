#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "items/item.h"
#include "player/player.h"
using namespace std;


Player::Player(const string& name, int health, int armor, int faith, int level) : name(name), health(health), armor(armor), faith(faith), level(level) {}

Player::attack(Enemy& enemy) {
        
}

Player::takeDamage(int dmg) {
        
}

Player::useItem() {

}

activateAbility() {

}

displayStatus() {
    return name;
    return health;
    return armor;
    return faith;
    return level;
    return inventory;
}
