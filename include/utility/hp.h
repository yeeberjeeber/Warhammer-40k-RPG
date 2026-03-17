#pragma once
#include "types.h"

// class dealing with HP interactions

class HP {
private:
    hptype Armor;
    hptype CurrentHealth;
    hptype MaxHealth;

public:
    bool setMaxHP(hptype newMaxHP) {}
    void takeDamage(hptype Damage) {}
    void heal(hptype Amount) {}

    // getters
    hptype getMaxHP() const { return MaxHealth; }
    hptype getCurrentHP() const { return CurrentHealth; }
    hptype getArmor() const { return Armor; }
};