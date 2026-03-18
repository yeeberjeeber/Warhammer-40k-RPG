#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "items/item.h"
#include "player/player.h"
#include "utility/types.h"
using namespace std;

Player::Player() : name("Jon Wingard"), health(50, 100, 100), faith(50, 50), level(1, 0) {};

Player::Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, ui8 cLevel, ui16 cEXP) : name(name), health(armor, cHealth, mHealth), faith(cFaith, mFaith), level(cLevel, cEXP) {};

// void Player::attack(Enemy& enemy) {
        
// }

void Player::takeDamage(ui16 dmg) {
    health.takeDamage(dmg);
}

void Player::useItem() {

}

void Player::activateAbility() {

}

void Player::calcEXP(ui16 gainedEXP) {
    level.gainEXP(gainedEXP);
}