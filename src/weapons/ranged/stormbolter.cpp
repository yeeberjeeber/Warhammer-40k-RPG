#include <iostream>
#include "utility/types.h"
#include "weapons/ranged/stormbolter.h"
using namespace std;

StormBolter::StormBolter() {
    // stats
    name = "Storm Bolter";
    type = false;
    damage = 75;
    ammo = 12;

    requiredStr = 22;
    requiredDex = 16;
    requiredIntel = 15;
}