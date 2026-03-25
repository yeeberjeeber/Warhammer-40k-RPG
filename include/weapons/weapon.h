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
    ui16 ammo;

    ui16 requiredStr;
    ui16 requiredDex;
    ui16 requiredIntel;

    StatBlock stats;

public:
    string getName() const { return name; }
    ui16 getDamage() const { return damage; }
    ui16 getAmmo() const { return ammo; }
    bool requiredStats(ui16 rStr, ui16 rDex, ui16 rIntel);
    ui16 calcDamage(bool type);
    virtual ~Weapon() = default; // virtual destructor
};  