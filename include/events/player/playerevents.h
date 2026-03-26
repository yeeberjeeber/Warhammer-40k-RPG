#pragma once
#include "utility/types.h"
#include "player/player.h"
#include "enemy/enemies.h"

class PlayerEvents {
private:
    mt rng { random_device {}() };
    void checkAmmo(Player& player);
    void PlayerChoice(Player& player, Enemy& enemy);
    void SelectChoice(ui16 choice, Player& player, Enemy& enemy);
    void ScanEnemy(Enemy& enemy);

public:
    mt& getRNG();
    void PlayerOption(Player& player, Enemy& enemy);
};