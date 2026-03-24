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

    // base health stats:
    ui16 StartingHealth = 150;
    ui16 StartingArmor = 50;

    // base faith stats:
    ui16 StartingFaith = 50;

    // base stats:
    ui16 baseStr = 23;
    ui16 baseDex = 19;
    ui16 baseIntel = 17;
    ui16 baseSpd = 20;

    // damage formula:
    ui16 meleeDamage = (baseStr * 1.5) + (baseDex * 0.25);
    ui16 rangedDamage = (baseDex * 1.5) + (baseStr * 0.25);

    HP health;
    Faith faith;
    StatBlock stats;
    Levelling level;

public:
    Player();
    Player(const string& name, ui8 cHealth, ui8 mHealth, ui8 armor, ui8 cFaith, ui8 mFaith, ui8 cLevel, ui16 cEXP);

    void takeDamage(ui16 dmg);
    ui16 ChainswordSlash();
    ui16 BolterFire();
    void useItem();
    void activateAbility();
    void calcEXP(ui16 gainedEXP);
    bool isAlive();
    void gainStats();
    

    void displayStatus() {
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Health: " << health.getCurrentHP() << "/" << health.getMaxHP() << endl;
        cout << "Armor: " << health.getArmor() << endl;
        cout << "Faith: " << faith.getCurrentFaith() << "/" << faith.getMaxFaith() << endl;
        cout << "Level: " << level.getCurrentLevel() << endl;
        cout << "Current EXP: " << level.getCurrentEXP() << "/" << level.getEXPCap() << endl;
        cout << endl;
    };

    void displayStats() {
        cout << endl;
        cout << "Strength: " << stats.getStr() << endl;
        cout << "Dexterity: " << stats.getDex() << endl;
        cout << "Intelligence: " << stats.getIntel() << endl;
        cout << "Speed: " << stats.getSpeed() << endl;
        cout << endl;
    }
};  