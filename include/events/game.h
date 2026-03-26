#pragma once
#include "utility/types.h"
#include "player/player.h"

class GameEvents {
private:
    unique_ptr<Player> p = nullptr;

public:
    void GameStart();
    bool GameOver(Player& player);
};