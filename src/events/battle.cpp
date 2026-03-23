#include <iostream>
#include "utility/types.h"
#include "player/player.h"
#include "events/battle.h"
#include "enemy/enemy.h"
#include <vector>
using namespace std;

// 1v1 Battle Scenario
void BattleEvents::Battle(Player& player, Enemy& enemy) {
    cout << "<------------------- GAME START ---------------->" << endl;
    BattleStart(player, enemy);

    while (player.isAlive() && enemy.isAlive()) {
        PlayerChoice(player, enemy);
        if (enemy.isAlive()) {
            player.takeDamage(enemy.getAttackDamage());
        } else {
            player.calcEXP(enemy.onDeath());
            BattleEnd(player);
        }
    }
}

void BattleEvents::BattleMultipleTyranids(Player& player) {
    cout << "<------------------- GAME START ---------------->" << endl;
    auto enemies = SpawnTyranidEnemies();

    for (auto& e : enemies) {
        if (!player.isAlive()) break;

        while(player.isAlive() && e->isAlive()) {
            SelectTarget(player, enemies);

            for (auto& e : enemies) {
                if (e->isAlive()) {
                    player.takeDamage(e->getAttackDamage());
                    cout << "Enemy attacks for " << e->getAttackDamage() << " damage!" << endl;
                } else {
                    player.calcEXP(e->onDeath());
                } 
            }
        }

        for (auto& e : enemies) {
            if (e->isAlive()) {
                e->synapseCheck();
            }
        }
    }
}

void BattleEvents::ScanEnemy(Enemy& enemy) {
    cout << "Upon contact with a hostile, your helmet's integrated scanner pulls up threat assessment data:" << endl;
    enemy.displayStats();
    cout << "Prepare for battle." << endl;
    cout << endl;
    cout << "<------------------- BATTLE START ---------------->" << endl;
}

void BattleEvents::SelectTarget(Player& player, vector<unique_ptr<Tyranid>>& enemies) {
    cout << endl;
    cout << "Enemies: " << endl;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->isAlive()) {
            cout << "[" << i + 1 << "]" << endl;
            enemies[i]->displayStats();
        }
    }

    cout << endl;
    cout << "Select a target:" << endl;
    int target;
    cin >> target;
    target--;

    if (target < 0 || target >= enemies.size() || !enemies[target]->isAlive()) {
        cout << "Invalid target." << endl;
        return;
    }

    cout << "You make another choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    int choice;
    cout << "[1] Bolter" << endl;
    cout << "[2] Chainsword" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            enemies[target]->takeDamage(player.BolterFire());
            break;
        case 2:
            enemies[target]->takeDamage(player.ChainswordSlash());
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}

void BattleEvents::PlayerChoice(Player& player, Enemy& enemy) {
    cout << "You make a choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    int choice;
    cout << "[1] Bolter" << endl;
    cout << "[2] Chainsword" << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            enemy.takeDamage(player.BolterFire());
            break;
        case 2:
            enemy.takeDamage(player.ChainswordSlash());
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}

void BattleEvents::BattleStart(Player& player, Enemy& enemy) {
    cout << endl;
    player.displayStatus();
    cout << endl;
    cout << "Player Stats:" << endl;
    player.displayStats();
    cout << endl;
    ScanEnemy(enemy);
}

void BattleEvents::BattleEnd(Player& player) {
    cout << "<------------------- BATTLE END ---------------->" << endl;
    cout << endl;
    cout << "Status: " << endl;
    player.displayStatus();
}

vector<unique_ptr<Tyranid>> BattleEvents::SpawnTyranidEnemies() {
    vector<unique_ptr<Tyranid>> enemies;

    ui16 numHormagaunts = rand() % 3 + 1;
    ui16 numTermagaunts = rand() % 3 + 1;
    ui16 numCarnifexes = rand() % 2 + 1;

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

    return enemies;
}