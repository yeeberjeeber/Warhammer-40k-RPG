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
        pEvents.PlayerOptionOneEnemy(player, enemy);
        if (enemy.isAlive()) {
            player.takeDamage(enemy.getAttackDamage());
        } else {
            player.calcEXP(enemy.onDeath());
            BattleEnd(player);
        }
    }
}

// Tyranid swarm methods
void BattleEvents::BattleMultipleTyranids(Player& player) {
    cout << "<------------------- GAME START ---------------->" << endl;
    auto enemies = eEvents.SpawnTyranidEnemies(player);

    // populating new vector to pass into function
    vector<unique_ptr<Enemy>> enemyVector;
    for (auto& ene : enemies) {
        enemyVector.push_back(move(ene));
    }

    while(player.isAlive() && !enemyVector.empty()) {
        pEvents.PlayerOptionMultEnemies(player, enemyVector);

        for (auto& e : enemyVector) {
            if (!e->isAlive()) {
                player.calcEXP(e->onDeath());
                continue;
            };

            if (Tyranid* t = dynamic_cast<Tyranid*>(e.get())) {
                bool deadSynapse = t->synapseCheck();   // check if synapse source is not alive
                if (deadSynapse) {
                    cout << "\n" << t->getName() << " falls to the ground, lifeless." << endl;
                    player.calcEXP(t->onDeath());
                    continue;
                }
            }

            player.takeDamage(e->getAttackDamage());
            cout << e->getName() << " attacks for " << e->getAttackDamage() << " damage!" << endl << "\n";
        }

        for(auto it = enemyVector.begin(); it != enemyVector.end(); ) {
            if(!(*it)->isAlive()) {
                it = enemyVector.erase(it);
            }
            else {
                ++it;
            }
        }
    }
}

void BattleEvents::SelectTarget(Player& player, vector<unique_ptr<Tyranid>>& enemies) {
    cout << endl;
    cout << "Enemies: " << endl;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->isAlive()) {
            cout << "[" << i + 1 << "]" << " " << enemies[i]->getName() << endl;
            enemies[i]->displayStats();
            cout << endl;
        }
    }

    cout << endl;
    cout << "Select a target:" << endl;
    int target;
    cin >> target;
    target--;      // making it 0 indexed

    if (target < 0 || target >= enemies.size() || !enemies[target]->isAlive()) {
        cout << "Invalid target." << endl;
        return;
    }

    cout << "You make another choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    int choice;
    cout << "[1] " << player.getPrimaryName() << endl;
    cout << "[2] " << player.getSecondaryName() << endl;
    cout << "[3] " << player.getMeleeName() << endl;
    cin >> choice;

    switch(choice) {
        case 1:
            enemies[target]->takeDamage(player.getPrimaryDamage());
            cout << "Enemy takes " << player.getPrimaryDamage() << "damage!" << endl;
            break;
        case 2:
            enemies[target]->takeDamage(player.getSecondaryDamage());
            cout << "Enemy takes " << player.getSecondaryDamage() << "damage!" << endl;
            break;
        case 3:
            enemies[target]->takeDamage(player.getMeleeDamage());
            cout << "Enemy takes " << player.getMeleeDamage() << "damage!" << endl;
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}

void BattleEvents::BattleStart(Player& player, Enemy& enemy) {
    cout << "<------------------- BATTLE START ---------------->" << endl;
    cout << endl;
    player.displayStatus();
    cout << endl;
    cout << "Player Stats:" << endl;
    player.displayStats();
    cout << endl;
}

void BattleEvents::BattleEnd(Player& player) {
    cout << "<------------------- BATTLE END ---------------->" << endl;
    cout << endl;
    cout << "Status: " << endl;
    player.displayStatus();
}