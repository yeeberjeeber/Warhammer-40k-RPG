#pragma once
#include "types.h"

// class dealing with any faith interactions

class Faith {
private:
    ui16 CurrentFaith;
    ui16 MaxFaith;

public:
    // default constructor
    Faith();

    // overloaded constructor
    Faith(ui16 cFaith, ui16 mFaith);

    bool setMaxFaith(ui16 NewFaithVal);
    void consumeFaith(ui16 FaithAmt);
    void regainFaith(ui16 FaithAmt);

    ui16 getCurrentFaith() { return CurrentFaith; }
    ui16 getMaxFaith() { return MaxFaith; }
};