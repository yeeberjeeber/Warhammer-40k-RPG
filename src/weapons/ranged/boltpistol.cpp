#include <iostream>
#include "utility/types.h"
#include "weapons/ranged/boltpistol.h"
using namespace std;

BoltPistol::BoltPistol() {
    // stats
    name = "Bolt Pistol";
    type = false;
    damage = 25;
    ammo = 25;

    requiredStr = 9;
    requiredDex = 8;
    requiredIntel = 9;
}