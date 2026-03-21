#include <iostream>
#include "utility/types.h"
#include "player/player.h"
#include "events/battle.h"
#include "enemy/enemy.h"
using namespace std;

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

void BattleEvents::ScanEnemy(Enemy& enemy) {
    cout << "Upon contact with a hostile, your helmet's integrated scanner pulls up threat assessment data:" << endl;
    enemy.displayStats();
    cout << "Prepare for battle." << endl;
    cout << endl;
    cout << "<------------------- BATTLE START ---------------->" << endl;
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