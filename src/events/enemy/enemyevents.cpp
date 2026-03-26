#include <iostream>
#include "utility/types.h"
#include "enemy/enemies.h"
#include "events/enemy/enemyevents.h"
#include <random>
#include <algorithm>
using namespace std;

mt& EnemyEvents::getRNG() {
    return rng;
}

// Spawning Tyranid swarm
vector<unique_ptr<Tyranid>> EnemyEvents::SpawnTyranidEnemies(Player& player) {
    vector<unique_ptr<Tyranid>> enemies;
    vector<unique_ptr<Tyranid>> enemyType;

    enemyType.push_back(make_unique<Hormagaunt>());
    enemyType.push_back(make_unique<Termagaunt>());
    enemyType.push_back(make_unique<Carnifex>());

    for (auto& e : enemyType) {
        if (player.getCurrentLevel() < e->getMinLevel()) continue;
        ui16 maxVariants = min(5, 1 + (player.getCurrentLevel() / e->getWeightage() * 1));

        uniform_int_distribution<int> dist(1, maxVariants);
        int count = dist(rng);

        cout << count << " " << e->getName() << "(s) appeared!" << endl;

         for (int i = 0; i < count; i++) {
            if (e->getName() == "Hormagaunt") {
                enemies.push_back(make_unique<Hormagaunt>());
            }
            else if (e->getName() == "Termagaunt") {
                enemies.push_back(make_unique<Termagaunt>());
            }
            else if (e->getName() == "Carnifex") {
                enemies.push_back(make_unique<Carnifex>());
            }
         }
    }

    // setting up synapse links
    vector<Tyranid*> ptrs;

    for (auto& e : enemies) {
        ptrs.push_back(e.get());
    }

    for (auto& e : enemies) {
        e->synapseLink(ptrs);
    }

    shuffle(begin(enemies), end(enemies), getRNG()); // shuffle out the vector of Tyranids

    return enemies;
}

bool EnemyEvents::IsSingleEnemy(Player& player, double baseChanceSingle) {
    //chance decreases as player level increases
    double chance = max(0.2, baseChanceSingle - 0.05 * player.getCurrentLevel());

    uniform_real_distribution<double> dist(0.0, 1.0);
    double roll = dist(rng);

    return roll < chance; // true = single enemy, false = swarm
}