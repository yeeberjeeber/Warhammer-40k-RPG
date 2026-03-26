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

ui16 PlayerEvents::SelectTarget(vector<unique_ptr<Enemy>>& enemies) {
    cout << endl;
    cout << "Select a target:" << endl;
    ui16 target;
    cin >> target;
    target--;      // making it 0 indexed

    if (target < 0 || target >= enemies.size() || !enemies[target]->isAlive()) {
        cout << "Invalid target." << endl;
        return 0;
    }

    return target;
}

void PlayerEvents::SelectChoice(ui16 choice, Player& player, Enemy& enemy) {
    switch(choice) {
        case 1:
            if (player.getPrimaryAmmo() != 0) {
                enemy.takeDamage(player.getPrimaryDamage());
                cout << "\nEnemy takes " << player.getPrimaryDamage() << "damage!" << endl << "\n";
                break;
            }
            else {
                cout << "\nInvalid choice, weapon is empty." << endl << "\n";
            }
            break;
        case 2:
            if (player.getSecondaryAmmo() != 0) {
                enemy.takeDamage(player.getSecondaryDamage());
                cout << "\nEnemy takes " << player.getSecondaryDamage() << "damage!" << endl << "\n";
                break;
            }
            else {
                cout << "\nInvalid choice, weapon is empty." << endl << "\n";
            }
            break;
        case 3:
            enemy.takeDamage(player.getMeleeDamage());
            cout << "\nEnemy takes " << player.getMeleeDamage() << "damage!" << endl << "\n";
            break;
        default:
            cout << "\nInvalid choice. This world is unforgiving." << endl << "\n";
            break;
    }
}

void PlayerEvents::SelectChoiceMultEnemies(ui16 choice, Player& player, vector<unique_ptr<Enemy>>& enemies, ui16 target) {
    switch(choice) {
        case 1:
            if(player.getPrimaryAmmo() != 0) {
                enemies[target]->takeDamage(player.getPrimaryDamage());
                cout << "\nEnemy takes " << player.getPrimaryDamage() << "damage!" << endl << "\n";
                break;
            }
            else {
                cout << "\nInvalid choice, weapon is empty." << endl << "\n";
            }
            break;
        case 2:
            if(player.getSecondaryAmmo() != 0) {
                enemies[target]->takeDamage(player.getSecondaryDamage());
                cout << "\nEnemy takes " << player.getSecondaryDamage() << "damage!" << endl << "\n";
                break;
            }
            else {
                cout << "\nInvalid choice, weapon is empty." << endl << "\n";
            }
            break;
        case 3:
            enemies[target]->takeDamage(player.getMeleeDamage());
            cout << "\nEnemy takes " << player.getMeleeDamage() << "damage!" << endl << "\n";
            break;
        default:
            cout << "\nInvalid choice. This world is unforgiving." << endl<< "\n";
            break;
    }
}

void PlayerEvents::PlayerChoice(Player& player, Enemy& enemy) {
    cout << "<------------------- PLAYER TURN ---------------->" << endl;
    cout << "You make a choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    ui16 choice;
    checkAmmo(player);
    cin >> choice;

    SelectChoice(choice, player, enemy);
}

void PlayerEvents::PlayerChoiceMultEnemies(Player& player, vector<unique_ptr<Enemy>>& enemies) {
    ui16 target = SelectTarget(enemies);

    cout << "\nYou make a choice — engage from distance with bolter fire, or close the gap and let the chainsword do its work:" << endl;

    ui16 choice;
    checkAmmo(player);
    cin >> choice;
    
    SelectChoiceMultEnemies(choice, player, enemies, target);
}

void PlayerEvents::ScanEnemy(Enemy& enemy) {
    cout << "\nUpon contact with a hostile, your helmet's integrated scanner pulls up threat assessment data:" << endl;
    enemy.displayStats();
    cout << "\nYou grip your weapon, ready for battle." << endl;
    cout << endl;
}

void PlayerEvents::PlayerOptionOneEnemy(Player& player, Enemy& enemy) {
    ui16 choice;
    cout << "[1] Attack" << endl;
    cout << "[2] Use Item" << endl;
    cout << "[3] Use Ability" << endl;
    cout << "[4] Run" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            ScanEnemy(enemy);
            PlayerChoice(player, enemy);
            break;
        case 4:
            cout << "There is no running." << endl;
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}

void PlayerEvents::PlayerOptionMultEnemies(Player& player, vector<unique_ptr<Enemy>>& enemies) {
    cout << "\n" << "Enemies: " << endl;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->isAlive()) {
            cout << "[" << i + 1 << "]" << " " << enemies[i]->getName() << endl;
            enemies[i]->displayStats();
            cout << endl;
        }
    }

    cout << "\n" << "<------------------- PLAYER TURN ---------------->" << endl << "\n";

    ui16 choice;
    cout << "[1] Attack" << endl;
    cout << "[2] Use Item" << endl;
    cout << "[3] Use Ability" << endl;
    cout << "[4] Run" << endl;
    cin >> choice;
    switch(choice) {
        case 1:
            PlayerChoiceMultEnemies(player, enemies);
            break;
        case 4:
            cout << "There is no running." << endl;
            break;
        default:
            cout << "Invalid choice. This world is unforgiving." << endl;
            break;
    }
}