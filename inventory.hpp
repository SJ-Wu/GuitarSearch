#pragma once
#include <list>
#include "guitar.hpp"
using namespace std;

class Inventory{
private:
    list<Guitar*> guitars;
public:
    void addGuitar(string serialNumber, double price, GuitarSpec spec);
    Guitar* getGuitar(string serialNumber);
    list<Guitar*> search(GuitarSpec* searchSpec);
};
