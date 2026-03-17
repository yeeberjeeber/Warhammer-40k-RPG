#include <iostream>
#include "utility/hp.h"
#include "utility/types.h"
using namespace std;

// returns true if set successful
bool HP::setMaxHP(hptype newMaxHP) {
    if (newMaxHP < 1) return false; // auto exit if HP is set to 0, handling our error case

        MaxHealth = newMaxHP;

        if (CurrentHealth > MaxHealth) CurrentHealth = MaxHealth;

        return true;
}

void HP::takeDamage(hptype Damage) {
    if (Damage > CurrentHealth) { // defaulting to 0 to avoid any negative cases
            CurrentHealth = 0;
            return;
        }

        CurrentHealth -= damage;
}

void HP::heal(hptype Amount) {
    if (Amount + CurrentHealth > MaxHealth) { // ensuring we do not overheal
            CurrentHealth = MaxHealth;
            return;
        }

        CurrentHealth += Amount;
}