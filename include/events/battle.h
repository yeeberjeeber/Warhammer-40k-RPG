#pragma once
#include "player/player.h"
#include "enemy/enemies.h"
#include <vector>

class BattleEvents {
public:
    static void Battle(Player& player, Enemy& enemy);
    static void BattleMultipleTyranids(Player& player);
    static void ScanEnemy(Enemy& enemy);
    static void PlayerChoice(Player& player, Enemy& enemy);
    static void SelectTarget(Player& player, vector<unique_ptr<Tyranid>>& enemies);
    static void BattleStart(Player& player, Enemy& enemy);
    static void BattleEnd(Player& player);
    static vector<unique_ptr<Tyranid>> SpawnTyranidEnemies();
};