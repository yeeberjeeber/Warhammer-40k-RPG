#include <iostream>
#include "utility/types.h"
#include "utility/stats.h"
#include "utility/hp.h"
#include "enemy/tyranids/tyranid.h"
#include "enemy/enemy.h"
#include <vector>
using namespace std;


void Tyranid::synapseLink(vector<Tyranid*>& tyranids) {
    Tyranid* highest = nullptr;

    for (auto& t : tyranids) {  // iterating over each item in tyranids vector
        if (t != this) {        // do not link to self
            if (highest == nullptr || t->weightage >= highest->weightage) {
                highest = t;
            }
        }
    }

    synapseSource = highest;
}

bool Tyranid::synapseCheck() {
    if (synapseSource != nullptr && !synapseSource->isAlive()) {
        takeDamage(health.getCurrentHP());
        return true;
    }

    return false;
}