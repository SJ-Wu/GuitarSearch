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
        Builder builder = searchSpec->getBuilder();
		if (builder == spec->getBuilder()) {
			string model = toLowerCase(searchSpec->getModel());
			if (model == spec->getModel()) {
				Type type = searchSpec->getType();
				if (type == spec->getType()) {
					Wood backWood = searchSpec->getBackWood();
					if (backWood == spec->getBackWood()) {
						Wood topWood = searchSpec->getTopWood();
						if (topWood == spec->getTopWood()) {
							matchingGuitars.push_back(guitar);
						}
					}
				}
			}
		}
    }
	return matchingGuitars;
}
