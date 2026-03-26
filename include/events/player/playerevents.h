#pragma once
#include "utility/types.h"
#include "player/player.h"
#include "enemy/enemies.h"

class PlayerEvents {
private:
    mt rng { random_device {}() };
    void checkAmmo(Player& player);
    void PlayerChoice(Player& player, Enemy& enemy);
    void PlayerChoiceMultEnemies(Player& player, vector<unique_ptr<Enemy>>& enemies);
    void SelectChoice(ui16 choice, Player& player, Enemy& enemy);
    void SelectChoiceMultEnemies(ui16 choice, Player& player, vector<unique_ptr<Enemy>>& enemies, ui16 target);
    void ScanEnemy(Enemy& enemy);
    ui16 SelectTarget(vector<unique_ptr<Enemy>>& enemies);

public:
    mt& getRNG();
    void PlayerOptionOneEnemy(Player& player, Enemy& enemy);
    void PlayerOptionMultEnemies(Player& player, vector<unique_ptr<Enemy>>& enemies);
};