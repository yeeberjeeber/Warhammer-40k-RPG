#pragma once
#include "utility/types.h"
#include "utility/stats.h"
#include <string>
using namespace std;

class Weapon {
protected:
    string name;
    bool type;
    ui16 damage;

    ui16 requiredStr;
    ui16 requiredDex;
    ui16 requiredIntel;

    StatBlock stats;

public:
    string getName() const { return name; }
    int getDamage() const { return damage; }
    bool requiredStats(ui16 rStr, ui16 rDex, ui16 rIntel);
    ui16 calcDamage(bool type);
    virtual ~Weapon() = default; // virtual destructor
};  