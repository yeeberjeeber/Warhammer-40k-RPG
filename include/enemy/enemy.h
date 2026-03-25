    #pragma once
    #include "utility/types.h"
    #include "utility/hp.h"
    #include "utility/stats.h"
    #include <string>

    class Enemy {
    protected:
        string Name;

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
        ui16 onDeath();
        void displayStats();
        string getName();
        ui16 getHealth();
        virtual ~Enemy() = default;
    };