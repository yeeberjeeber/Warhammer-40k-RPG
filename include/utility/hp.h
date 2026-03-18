#pragma once
#include "types.h"

// class dealing with HP interactions

class HP {
private:
    ui16 Armor;
    ui16 CurrentHealth;
    ui16 MaxHealth;

public:
    // default constructor
    HP() {};

    // overloaded constructor
    HP(ui16 armor, ui16 cHP, ui16 mHP) {};

    bool setMaxHP(ui16& newMaxHP) {}
    void takeDamage(ui16 Damage) {}
    void heal(ui16 Amount) {}

    // getters
    ui16 getMaxHP() const { return MaxHealth; }
    ui16 getCurrentHP() const { return CurrentHealth; }
    ui16 getArmor() const { return Armor; }
};