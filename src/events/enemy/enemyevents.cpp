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
vector<unique_ptr<Tyranid>> EnemyEvents::SpawnTyranidEnemies() {
    vector<unique_ptr<Tyranid>> enemies;

    ui16 numHormagaunts = rand() % 5 + 1;
    ui16 numTermagaunts = rand() % 4 + 1;
    ui16 numCarnifexes = rand() % 1 + 1;

    cout << endl;
    cout << numHormagaunts << " Hormgaunts appeared!" << endl;
    cout << numTermagaunts << " Termagaunts appeared!" << endl;
    cout << numCarnifexes << " Carnifexes appeared!" << endl;

    // populating enemies vector
    for (int i = 0; i < numHormagaunts; i++) {
        enemies.push_back(make_unique<Hormagaunt>()); // all Hormagaunts are the same
    }

    for (int i = 0; i < numTermagaunts; i++) {
        enemies.push_back(make_unique<Termagaunt>());
    }

    for (int i = 0; i < numCarnifexes; i++) {
        enemies.push_back(make_unique<Carnifex>());
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