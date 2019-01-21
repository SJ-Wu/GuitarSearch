#include "Inventory.hpp"
using namespace std;
void Inventory::addGuitar(string serialNumber, double price, GuitarSpec spec){
	Guitar* guitar = new Guitar(serialNumber, price, spec);
    guitars.push_back(guitar);
}

Guitar* Inventory::getGuitar(string serialNumber){
	list<Guitar*>::iterator iter = guitars.begin();
	Guitar* guitar = nullptr;
	guitar = *iter;
    for(; iter != guitars.end(); iter++){
        if (toLowerCase(guitar->getSerialNumber()) == serialNumber){
            return guitar;
        }
    }
	return nullptr;
};

list<Guitar*> Inventory::search(GuitarSpec* searchSpec){
	list<Guitar*> matchingGuitars;
	list<Guitar*>::iterator iter = guitars.begin();
	Guitar* guitar = nullptr;
	GuitarSpec* spec = nullptr;
	for(; iter != guitars.end(); iter++){
		guitar = *iter;
		spec = guitar->getSpec();
		if (searchSpec->matches(*spec) == true) {
			matchingGuitars.push_back(guitar);
		}
    }
	return matchingGuitars;
}
