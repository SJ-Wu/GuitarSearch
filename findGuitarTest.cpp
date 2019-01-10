#include "inventory.hpp"

class FindGuitarTester{
public:
    FindGuitarTester();
private:
    static void initializeInventory(Inventory* inventory);
};

void FindGuitarTester::initializeInventory(Inventory* inventory){
	inventory->addGuitar("V95693", 1499.95, "Fender", "Stratocastor", "electric", "Alder", "Alder");
}

FindGuitarTester::FindGuitarTester(){
    Inventory *inventory = new Inventory();
    initializeInventory(inventory);

    Guitar whatErinLikes("", 0, "fender", "Stratocastor", "electric", "Alder", "Alder");
    Guitar *guitar = inventory->search(&whatErinLikes);
    if (guitar != NULL){
		cout << "Erin, you might like this " << guitar->getBuilder() << " " << guitar->getModel() << " " << guitar->getType() << " guitar:\n";
		cout << guitar->getBackWood() << " back and sides,\n";
		cout << guitar->getTopWood() << " top.\nYou can have it for only $";
        cout << guitar->getPrice() << "!" << endl;
    } else {
        cout << "Sorry, Erin, we have nothing for you." << endl;
    }
}

int main (){
    FindGuitarTester test;
	getchar();
    return 0;
}
