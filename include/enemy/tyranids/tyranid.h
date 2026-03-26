    #pragma once
    #include "enemy/enemy.h"
    #include "utility/types.h"
    #include <vector>
    using namespace std;

    class Tyranid : public Enemy {
    protected:
        Tyranid* synapseSource = nullptr;

    public:
        // Tyranid Hive behaviour
        void synapseLink(vector<Tyranid*>& tyranids);
        bool synapseCheck();

        virtual ~Tyranid() = default;
    };