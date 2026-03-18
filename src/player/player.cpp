#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "items/item.h"
#include "player/player.h"
#include "utility/types.h"
using namespace std;

Player::Player() : health(), faith(), stats() {};

Player::Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, ui8 cLevel, ui16 cEXP) : name("Jon Wingard"), health(50, 100, 100), faith(50, 50), exp(1, 0) {};

void Player::attack(Enemy& enemy) {
        
}

void Player::takeDamage(ui16 dmg) {
    health.takeDamage(dmg);
}

void Player::useItem() {

}

void activateAbility() {

}