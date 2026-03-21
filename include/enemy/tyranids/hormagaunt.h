    #pragma once
    #include "enemy/enemy.h"
    #include "utility/types.h"
    #include "utility/hp.h"
    #include "utility/stats.h"

    class Hormagaunt : public Enemy {

    private:
        // stats
        ui16 BaseHealth = 11;
        ui16 BaseArmor = 5;
        ui16 BaseStr = 3;
        ui16 BaseDex = 6;
        ui16 BaseIntel = 1;
        ui16 BaseSpd = 17;

        // exp given
        ui16 EXP = 100;

        HP health;
        StatBlock stats;


    public:
        Hormagaunt();
        
        void takeDamage(ui16 dmg) override;
        ui16 getAttackDamage() override;
        bool isAlive() override;
        ui16 onDeath() override;
        void displayStats() override;
    };
