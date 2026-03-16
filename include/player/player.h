#pragma once
#include <string>
#include <vector>
#include <memory>
#include "items/item.h"
using namespace std;


class Player {
    private:
    string name;
    int health;
    int armor;
    int faith;
    int level;
    vector<shared_ptr<Item>> inventory;

    public:
    Player(const string& name, int health, int armor, int faith, int level);
    attack(Enemy& enemy);
    takeDamage(int dmg);
    useItem();
    activateAbility();
    displayStatus();
};  