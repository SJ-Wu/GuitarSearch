#include <iostream>
#include <list>
#include <string>
#include "guitar.hpp"
using namespace std;

class Inventory{
private:
    list<Guitar*> guitars;
public:
    void addGuitar(string serialNumber, double price, string builder, string model, string type,
        string backWood, string topWood);
    Guitar* getGuitar(string serialNumber);
    Guitar* search(Guitar* searchGuitar);
};
