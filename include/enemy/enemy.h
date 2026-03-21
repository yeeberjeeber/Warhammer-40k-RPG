#pragma once
#include "utility/types.h"

class Enemy {
public:
    virtual void takeDamage(ui16) = 0;
    virtual ui16 getAttackDamage() = 0;
    virtual bool isAlive() = 0;
    virtual ui16 onDeath() = 0;
    virtual void displayStats() = 0;
    virtual ~Enemy() = default;
};