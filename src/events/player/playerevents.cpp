#include <iostream>
#include "utility/types.h"
#include "enemy/enemies.h"
#include "events/player/playerevents.h"
#include <random>
#include <algorithm>
using namespace std;

mt& PlayerEvents::getRNG() {
    return rng;
}

void PlayerEvents::checkAmmo(Player& player) {
    // Primary Ammo check
    if (player.getPrimaryAmmo() > 0) {
        cout << "[1] " << player.getPrimaryName() << endl;
    } 
    else {
        cout << "Primary weapon empty." << endl;
    }
    
    // Secondary Ammo check
    if (player.getSecondaryAmmo() > 0) {
        cout << "[2] " << player.getSecondaryName() << endl;
    }
    else {
        cout << "Secondary weapon empty." << endl;
    }
    
    // Melee option
    cout << "[3] " << player.getMeleeName() << endl;
}

void PlayerEvents::selectChoice(ui16 choice, Player& player, Enemy& enemy) {
    switch(choice) {
        case 1:
            if (player.getPrimaryAmmo() != 0) {
                enemy.takeDamage(player.getPrimaryDamage());
                cout << "Enemy takes " << player.getPrimaryDamage() << "damage!" << endl;
                break;
            }
            else {
                cout << "Invalid choice, weapon is empty." << endl;
            }
        case 2:
            if (player.getSecondaryAmmo() != 0) {
                enemy.takeDamage(player.getSecondaryDamage());
                cout << "Enemy takes " << player.getSecondaryDamage() << "damage!" << endl;
                break;
            }
            else {
                cout << "Invalid choice, weapon is empty." << endl;
            }
        case 3:
            enemy.takeDamage(player.getMeleeDamage());
            cout << "Enemy takes " << player.getMeleeDamage() << "damage!" << endl;
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}

void PlayerEvents::PlayerChoice(Player& player, Enemy& enemy) {
    cout << "You make a choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    ui16 choice;
    checkAmmo(player);
    cin >> choice;

    selectChoice(choice, player, enemy);
}

void PlayerEvents::ScanEnemy(Enemy& enemy) {
    cout << "Upon contact with a hostile, your helmet's integrated scanner pulls up threat assessment data:" << endl;
    enemy.displayStats();
    cout << "You grip your weapon, ready for war." << endl;
    cout << endl;
}