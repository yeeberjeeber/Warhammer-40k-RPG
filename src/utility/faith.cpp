#include <iostream>
#include "utility/faith.h"
#include "utility/types.h"
using namespace std;

Faith::Faith() :  CurrentFaith(StartingFaith), MaxFaith(StartingFaith) {};

Faith::Faith(ui16 cFaith, ui16 mFaith) : CurrentFaith(cFaith), MaxFaith(mFaith) {};

// returns true if set successful
bool Faith::setMaxFaith(ui16 NewFaithVal) {
    if (NewFaithVal < 1) return false;

    MaxFaith = NewFaithVal;

    if (CurrentFaith > MaxFaith) CurrentFaith = MaxFaith;

    return true;
}

void Faith::consumeFaith(ui16 FaithAmt) {
    if (CurrentFaith < FaithAmt) {
        cout << "Insufficient Faith. May the Emperor protect." << endl;
        return;
    }

    CurrentFaith -= FaithAmt;
}

void Faith::regainFaith(ui16 FaithAmt) {
    if (CurrentFaith + FaithAmt > MaxFaith) {
        CurrentFaith = MaxFaith;
        return;
    }

    CurrentFaith += FaithAmt;
    cout << "Faith restored. The Emperor protects." << endl;
}