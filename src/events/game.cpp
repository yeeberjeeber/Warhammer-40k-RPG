#include <iostream>
#include "utility/types.h"
#include "events/game.h"
using namespace std;

void GameEvents::GameStart() {
    p = make_unique<Player>();
}

bool GameEvents::GameOver(Player& player) {
    if (!player.isAlive()) {
        return true;
    }

    return false;
}