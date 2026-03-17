#pragma once
#include "types.h"

// class dealing with any faith interactions

class Faith {
private:
    ui8 CurrentFaith;
    ui8 MaxFaith;

public:
    // default constructor
    Faith();

    // overloaded constructor
    Faith(ui8 mFaith, ui8 cFaith);

    bool setMaxFaith(ui8 NewFaithVal);
    void consumeFaith(ui8 FaithAmt);
    void regainFaith(ui8 FaithAmt);

    ui8 getCurrentFaith() { return CurrentFaith; }
    ui8 getMaxFaith() { return MaxFaith; }
};