#include <iostream>
#include "utility/hp.h"
#include "utility/types.h"
using namespace std;

HP::HP() : MaxHealth(1), CurrentHealth(1), Armor(1) {};

HP::HP(ui16 armor, ui16 cHP, ui16 mHP) : Armor(armor), CurrentHealth(cHP), MaxHealth(mHP) {};

// returns true if set successful
bool HP::setMaxHP(ui16 newMaxHP) {
    if (newMaxHP < 1) return false; // auto exit if HP is set to 0, handling our error case

        MaxHealth = newMaxHP;

        if (CurrentHealth > MaxHealth) CurrentHealth = MaxHealth;

        return true;
}

void HP::takeDamage(ui16 Damage) {
    if (Damage > CurrentHealth) { // defaulting to 0 to avoid any negative cases
            CurrentHealth = 0;
            return;
        }

        CurrentHealth -= Damage;
}

void HP::heal(ui16 Amount) {
    if (Amount + CurrentHealth > MaxHealth) { // ensuring we do not overheal
            CurrentHealth = MaxHealth;
            return;
        }

        CurrentHealth += Amount;
}