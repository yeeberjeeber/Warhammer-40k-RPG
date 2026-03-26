    #pragma once
    #include "utility/types.h"
    #include "utility/hp.h"
    #include "utility/stats.h"
    #include <string>
    using namespace std;

    struct EnemyType {
        string name;
        ui16 tier;
        ui16 minLevel;
        ui16 maxVariants;
    };

    class Enemy {
    protected:
        // stats
        string Name;
        ui16 BaseHealth;
        ui16 BaseArmor;
        ui16 BaseStr;
        ui16 BaseDex;
        ui16 BaseIntel;
        ui16 BaseSpd;
        ui16 weightage;
        ui16 MinLevel;

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
        ui16 getMinLevel() { return MinLevel; }
        ui16 getWeightage() { return weightage; }
        virtual ~Enemy() = default;
    };