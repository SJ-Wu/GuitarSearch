#include "Inventory.hpp"
using namespace std;
void Inventory::addGuitar(string serialNumber, double price, Builder builder, string model, Type type,
	Wood backWood, Wood topWood){
	Guitar* guitar = new Guitar(serialNumber, price, builder, model, type, backWood, topWood);
    guitars.push_back(guitar);
}

Guitar* Inventory::getGuitar(string serialNumber){
	list<Guitar*>::iterator iter = guitars.begin();
	Guitar* guitar = NULL;
	guitar = *iter;
    for(; iter != guitars.end(); iter++){
        if (toLowerCase(guitar->getSerialNumber()) == serialNumber){
            return guitar;
        }
    }
	return NULL;
};

Guitar* Inventory::search(Guitar* searchGuitar){
	list<Guitar*>::iterator iter = guitars.begin();
	Guitar* guitar = NULL;
	for(; iter != guitars.end(); iter++){
		guitar = *iter;
        Builder builder = searchGuitar->getBuilder();
		if (builder == guitar->getBuilder()) {
			string model = toLowerCase(searchGuitar->getModel());
			if (model == guitar->getModel()) {
				Type type = searchGuitar->getType();
				if (type == guitar->getType()) {
					Wood backWood = searchGuitar->getBackWood();
					if (backWood == guitar->getBackWood()) {
						Wood topWood = searchGuitar->getTopWood();
						if (topWood == guitar->getTopWood()) {
							return guitar;
						}
					}
				}
			}
		}
    }
	return NULL;
}
