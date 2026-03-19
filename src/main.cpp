#include <iostream>
#include "player/player.h"
using namespace std;

int main() {
	Player p;
	p.displayStatus();
	cout << "Stats display: " << endl;
	p.displayStats();
	
	return 0;
}
