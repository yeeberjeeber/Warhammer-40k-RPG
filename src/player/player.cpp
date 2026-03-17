#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "items/item.h"
#include "player/player.h"
#include "utility/types.h"
using namespace std;

Player::Player() : health(), faith(), stats() {};

Player::Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, int level) : name(name), health(armor, cHealth, mHealth), faith(mFaith, cFaith), level(level) {}

void Player::attack(Enemy& enemy) {
        
}

void Player::takeDamage(int dmg) {
        
}

void Player::useItem() {

}

void activateAbility() {

}

void levelUp(ui8 exp) {

}