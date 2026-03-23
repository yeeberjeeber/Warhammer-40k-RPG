    #pragma once
    #include "enemy/enemy.h"
    #include "utility/types.h"
    #include <vector>

    class Tyranid : public Enemy {

    protected:
        ui16 weightage;
        Tyranid* synapseSource = nullptr;

    public:
        // Tyranid Hive behaviour
        void synapseLink(vector<Tyranid*>& tyranids);
        void synapseCheck();

        virtual ~Tyranid() = default;
    };