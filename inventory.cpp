#include "Inventory.hpp"
using namespace std;
void Inventory::addGuitar(string serialNumber, double price, string builder, string model, string type, string backWood, string topWood){
	Guitar* guitar = new Guitar(serialNumber, price, builder, model, type, backWood, topWood);
    guitars.push_back(guitar);
}

Guitar* Inventory::getGuitar(string serialNumber){
	list<Guitar*>::iterator iter = guitars.begin();
	Guitar* guitar = NULL;
	guitar = *iter;
    for(; iter != guitars.end(); iter++){
        if (guitar->getSerialNumber() == serialNumber){
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
        string builder = searchGuitar->getBuilder();
		if (builder == guitar->getBuilder()) {
			string model = searchGuitar->getModel();
			if (model == guitar->getModel()) {
				string type = searchGuitar->getType();
				if (type == guitar->getType()) {
					string backWood = searchGuitar->getBackWood();
					if (backWood == guitar->getBackWood()) {
						string topWood = searchGuitar->getTopWood();
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
