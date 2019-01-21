#pragma once
#include "inventory.hpp"

class FindGuitarTester{
public:
    FindGuitarTester();
private:
    static void initializeInventory(Inventory* inventory);
};

void FindGuitarTester::initializeInventory(Inventory* inventory){
	inventory->addGuitar("V95693", 1499.95, GuitarSpec(FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6));
	inventory->addGuitar("V94600", 1399.00, GuitarSpec(FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6));
}

FindGuitarTester::FindGuitarTester(){
    Inventory *inventory = new Inventory();
    initializeInventory(inventory);

    GuitarSpec whatErinLikes(FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER, 6);
    list<Guitar*> matchingGuitars = inventory->search(&whatErinLikes);
	if (matchingGuitars.empty()) {
		cout << "Sorry, Erin, we have nothing for you." << endl;
	}
	else {
		list<Guitar*>::iterator iter = matchingGuitars.begin();
		Guitar* guitar = nullptr;
		GuitarSpec* spec = nullptr;
		for (; iter != matchingGuitars.end(); iter++) {
			guitar = *iter;
			spec = guitar->getSpec();
			cout << "Erin, you might like this " << Builder2String(spec->getBuilder()) << " " << spec->getModel() << " " << Type2String(spec->getType()) << " guitar:\n";
			cout << Wood2String(spec->getBackWood()) << " back and sides,\n";
			cout << Wood2String(spec->getTopWood()) << " top.\nNumber of strings " << spec->getNumStrings() << " \nYou can have it for only $";
			cout << guitar->getPrice() << "!" << endl;
		}
	}
}

int main (){
    FindGuitarTester test;
	getchar();
    return 0;
}
