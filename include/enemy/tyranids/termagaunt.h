    #pragma once
    #include "enemy/enemy.h"
    #include "enemy/tyranids/tyranid.h"
    #include "utility/types.h"
    #include "utility/hp.h"
    #include "utility/stats.h"

    class Termagaunt : public Tyranid {
    public:
        Termagaunt();

        ui16 onDeath() override;
    };