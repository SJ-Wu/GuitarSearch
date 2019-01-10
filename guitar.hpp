#include <string>
using namespace std;

class Guitar{
private:
    string serialNumber, builder, model, type, backWood, topWood;
    double price;
public:
	Guitar();
    Guitar(string serialNumber, double price, string builder, string model, string type, string backWood, string topWood);
	string getSerialNumber() { return serialNumber; }
	double getPrice() { return price; }
	string getBuilder() { return builder; }
	string getModel() { return model; }
	string getType() { return type; }
	string getBackWood() { return backWood; }
	string getTopWood() { return topWood; }
};
