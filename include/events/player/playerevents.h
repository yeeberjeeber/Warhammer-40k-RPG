#pragma once
#include "utility/types.h"
#include "player/player.h"
#include "enemy/enemies.h"

class PlayerEvents {
private:
    mt rng { random_device {}() };

public:
    mt& getRNG();
    void checkAmmo(Player& player);
    void selectChoice(ui16 choice, Player& player, Enemy& enemy);
    void PlayerChoice(Player& player, Enemy& enemy);
    void ScanEnemy(Enemy& enemy);
};