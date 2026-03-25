#include <iostream>
#include "utility/types.h"
#include "weapons/melee/chainsword.h"
using namespace std;

Chainsword::Chainsword() {
    // stats
    name = "Chainsword";
    type = true;
    damage = 50;

    requiredStr = 15;
    requiredDex = 10;
    requiredIntel = 5;
}