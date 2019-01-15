#pragma once
#include <list>
#include "guitar.hpp"
using namespace std;

class Inventory{
private:
    list<Guitar*> guitars;
public:
    void addGuitar(string serialNumber, double price, Builder builder, string model, Type type,
        Wood backWood, Wood topWood);
    Guitar* getGuitar(string serialNumber);
    list<Guitar*> search(Guitar* searchGuitar);
};
