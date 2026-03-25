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
        pEvents.PlayerChoice(player, enemy);
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
    auto enemies = eEvents.SpawnTyranidEnemies();

    for (auto& en : enemies) {
        if (!player.isAlive()) break;

        while(player.isAlive() && en->isAlive()) {
            SelectTarget(player, enemies);

            for (auto& e : enemies) {
                if (e->isAlive()) {
                    e->synapseCheck();   // check if synapse source is not alive
                    if (e->synapseCheck()) {
                        cout << "Enemy falls to the ground, lifeless." << endl;
                        player.calcEXP(e->onDeath());
                    }
                    else {
                        player.takeDamage(e->getAttackDamage());
                        cout << "Enemy attacks for " << e->getAttackDamage() << " damage!" << endl;
                        cout << endl;
                    }
                }
                else {
                    cout << "Enemy falls to the ground, lifeless." << endl;
                    player.calcEXP(e->onDeath());
                }
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
    pEvents.ScanEnemy(enemy);
}

void BattleEvents::BattleEnd(Player& player) {
    cout << "<------------------- BATTLE END ---------------->" << endl;
    cout << endl;
    cout << "Status: " << endl;
    player.displayStatus();
}