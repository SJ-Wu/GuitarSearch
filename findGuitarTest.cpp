#pragma once
#include "inventory.hpp"

class FindGuitarTester{
public:
    FindGuitarTester();
private:
    static void initializeInventory(Inventory* inventory);
};

void FindGuitarTester::initializeInventory(Inventory* inventory){
	inventory->addGuitar("V95693", 1499.95, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER);
	inventory->addGuitar("V94600", 1399.00, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER);
}

FindGuitarTester::FindGuitarTester(){
    Inventory *inventory = new Inventory();
    initializeInventory(inventory);

    Guitar whatErinLikes("", 0, FENDER, "Stratocastor", ELECTRIC, ALDER, ALDER);
    list<Guitar*> matchingGuitars = inventory->search(&whatErinLikes);
	if (matchingGuitars.empty()) {
		cout << "Sorry, Erin, we have nothing for you." << endl;
	}
	else {
		list<Guitar*>::iterator iter = matchingGuitars.begin();
		Guitar* guitar = NULL;
		for (; iter != matchingGuitars.end(); iter++) {
			guitar = *iter;
			cout << "Erin, you might like this " << Builder2String(guitar->getBuilder()) << " " << guitar->getModel() << " " << Type2String(guitar->getType()) << " guitar:\n";
			cout << Wood2String(guitar->getBackWood()) << " back and sides,\n";
			cout << Wood2String(guitar->getTopWood()) << " top.\nYou can have it for only $";
			cout << guitar->getPrice() << "!" << endl;
		}
	}
}

int main (){
    FindGuitarTester test;
	getchar();
    return 0;
}
