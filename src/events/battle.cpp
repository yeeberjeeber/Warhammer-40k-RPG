#include <iostream>
#include "utility/types.h"
#include "player/player.h"
#include "events/battle.h"
#include "enemy/enemy.h"
using namespace std;

void BattleEvents::Battle(Player& player, Enemy& enemy) {
    player.displayStatus();
    ScanEnemy(enemy);

    while (player.isAlive() && enemy.isAlive()) {
        PlayerChoice(player, enemy);
        if (enemy.isAlive()) {
            player.takeDamage(enemy.getAttackDamage());
            cout << enemy.isAlive() << endl;
        } else {
            player.calcEXP(enemy.onDeath());
            cout << "Current Stats: " << endl;
            player.displayStatus();
        }
    }
    
}

void BattleEvents::ScanEnemy(Enemy& enemy) {
    cout << "Upon contact with a hostile, your helmet's integrated scanner pulls up threat assessment data:" << endl;
    enemy.displayStats();
    cout << "Prepare for battle." << endl;
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