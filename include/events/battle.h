#pragma once
#include "player/player.h"
#include "enemy/enemies.h"

class BattleEvents {
public:
    static void Battle(Player& player, Enemy& enemy);

    static void ScanEnemy(Enemy& enemy);

    static void PlayerChoice(Player& player, Enemy& enemy);
};