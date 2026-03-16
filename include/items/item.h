#pragma once
#include <string>
using namespace std;

class Item {
    protected:
    string name;
    int weight;

    public:
    Item(const string& n, int w) : name(n), weight(w) {};

    virtual ~Item() = default; // 
    virtual void use() = 0;

    string getName() const { return name; }
    int getWeight() const { return weight; }
};  