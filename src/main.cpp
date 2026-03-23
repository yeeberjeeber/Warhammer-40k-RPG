#include <iostream>
#include "player/player.h"
#include "enemy/enemies.h"
#include "events/battle.h"
using namespace std;

int main() {
	Player p;

	BattleEvents::BattleMultipleTyranids(p);

	return 0;
}
