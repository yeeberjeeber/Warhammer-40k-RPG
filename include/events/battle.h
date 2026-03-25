#pragma once
#include "player/player.h"
#include "enemy/enemies.h"
#include "events/enemy/enemyevents.h"
#include "events/player/playerevents.h"
#include <vector>

class BattleEvents {
private:
    EnemyEvents eEvents;
    PlayerEvents pEvents;

public:
    void Battle(Player& player, Enemy& enemy);
    void BattleMultipleTyranids(Player& player);
    void SelectTarget(Player& player, vector<unique_ptr<Tyranid>>& enemies);
    void BattleStart(Player& player, Enemy& enemy);
    void BattleEnd(Player& player);
};