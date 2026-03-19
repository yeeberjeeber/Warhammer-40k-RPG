#pragma once
#include <string>
#include <vector>
#include <memory>
#include "items/item.h"
#include "utility/hp.h"
#include "utility/faith.h"
#include "utility/stats.h"
#include "utility/levelling.h"
#include "utility/types.h"
using namespace std;


class Player {
private:
    string name;
    HP health;
    Faith faith;
    StatBlock stats;
    Levelling level;

public:
    Player();
    Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, ui8 cLevel, ui16 cEXP);

    // void attack(Enemy& enemy) {};
    void takeDamage(ui16 dmg);
    void useItem();
    void activateAbility();
    void calcEXP(ui16 gainedEXP);

    void displayStatus() {
        cout << "Name: " << name << endl;
        cout << "Health: " << health.getCurrentHP() << "/" << health.getMaxHP() << endl;
        cout << "Armor: " << health.getArmor() << endl;
        cout << "Faith: " << faith.getCurrentFaith() << "/" << faith.getMaxFaith() << endl;
        cout << "Level: " << level.getCurrentLevel() << endl;
        cout << "Current EXP: " << level.getCurrentEXP() << "/" << level.getMaxEXP() << endl;
    };

    void displayStats() {
        cout << "Strength: " << stats.getStr() << endl;
        cout << "Dexterity: " << stats.getDex() << endl;
        cout << "Intelligence: " << stats.getIntel() << endl;
        cout << "Speed: " << stats.getSpeed() << endl;
    }
};  