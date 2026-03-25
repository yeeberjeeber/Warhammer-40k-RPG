#include <iostream>
#include "utility/types.h"
#include "weapons/weapon.h"
using namespace std;

bool Weapon::requiredStats(ui16 rStr, ui16 rDex, ui16 rIntel) {
    if (rStr == requiredStr && rDex == requiredDex && rIntel == requiredIntel) {
        cout << "The weapon feels light in your hands." << endl;
        return true;
    }
    cout << "The weapon feels heavy, impacting your performance." << endl;
    damage /= 2;
    return false;
}

ui16 Weapon::calcDamage(bool type) {
    if (type) {
        damage = (requiredStr * 1.5) + (requiredDex * 0.25);
        return damage;
    }

    damage = (requiredDex * 1.5) + (requiredStr * 0.25);
    return damage;
}