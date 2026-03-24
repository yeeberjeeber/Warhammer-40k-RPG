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

    cout << synapseSource->getName() << endl;
}

void Tyranid::synapseCheck() {
    if (synapseSource != nullptr && !synapseSource->isAlive()) {
        cout << "Own health damaged: " << health.getCurrentHP() << endl;
        takeDamage(health.getCurrentHP());
        cout << "Current Health: " << health.getCurrentHP() << endl;
    }
}