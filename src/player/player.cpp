#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "items/item.h"
#include "player/player.h"
#include "utility/types.h"
#include "weapons/weapon.h"
using namespace std;

Player::Player() : name("John Wingard"), 
                   health(StartingArmor, StartingHealth, StartingHealth), 
                   faith(StartingFaith, StartingFaith), 
                   level(), 
                   stats(baseStr, baseDex, baseIntel, baseSpd) { initialiseLoadout(); }

Player::Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, ui8 cLevel, ui16 cEXP) : name(name), health(armor, cHealth, mHealth), faith(cFaith, mFaith), level(cLevel, cEXP) {};

ui16 Player::ChainswordSlash() {
    return meleeDamage;
}

ui16 Player::BolterFire() {
    return rangedDamage;
}

void Player::takeDamage(ui16 dmg) {
    health.takeDamage(dmg);
}

void Player::useItem() {

}

void Player::activateAbility() {

}

void Player::calcEXP(ui16 gainedEXP) {
    if (level.gainEXP(gainedEXP)) {
        health.setMaxHP(50);
        health.fullHeal();
        cout << endl;
        cout << "<------------------- STATUS DISPLAY ---------------->" << endl;
        cout << "Current Status: " << endl;
        displayStatus();
        gainStats();
        cout << "New Stats:" << endl;
        displayStats();
        cout << "<--------------------------------------------------->" << endl;
    }
}

void Player::initialiseLoadout() {
    Primary = make_unique<StormBolter>();
    Secondary = make_unique<BoltPistol>();
    Melee = make_unique<Chainsword>();
}

ui16 Player::getHealth() {
    return health.getCurrentHP();
}

bool Player::isAlive() {
    return health.isAlive(health.getCurrentHP());
}


void Player::gainStats() {
    stats.gainStr(9);
    stats.gainDex(5);
    stats.gainIntel(4);
    stats.gainSpd(6);
    cout << "Your strength is bolstered." << endl;
}