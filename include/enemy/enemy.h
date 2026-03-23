    #pragma once
    #include "utility/types.h"
    #include "utility/hp.h"
    #include "utility/stats.h"

    class Enemy {
    protected:
        // stats
        ui16 BaseHealth;
        ui16 BaseArmor;
        ui16 BaseStr;
        ui16 BaseDex;
        ui16 BaseIntel;
        ui16 BaseSpd;

        // exp given
        ui16 EXP;

        HP health;
        StatBlock stats;

    public:
        void takeDamage(ui16);
        ui16 getAttackDamage();
        bool isAlive();
        virtual ui16 onDeath() = 0;
        void displayStats();
        virtual ~Enemy() = default;
    };