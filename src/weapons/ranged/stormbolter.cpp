#include <iostream>
#include "utility/types.h"
#include "weapons/ranged/stormbolter.h"
using namespace std;

StormBolter::StormBolter() {
    // stats
    name = "Bolt Pistol";
    type = false;
    damage = 75;

    requiredStr = 22;
    requiredDex = 16;
    requiredIntel = 15;
}