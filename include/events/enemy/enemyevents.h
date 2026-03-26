#pragma once
#include "utility/types.h"
#include "player/player.h"
#include "enemy/enemies.h"
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

class EnemyEvents {
private:
    mt rng { random_device {}() };

public:
    mt& getRNG();
    vector<unique_ptr<Tyranid>> SpawnTyranidEnemies(Player& player);
    bool IsSingleEnemy(Player& player, double baseChanceSingle = 0.6);
};