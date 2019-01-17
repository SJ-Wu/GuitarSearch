#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

enum Type{
	ACOUSTIC,
	ELECTRIC,
	TYPEMAX
};

enum Builder{
	FENDER,
	MARTIN,
	BUILDERMAX
};

enum Wood {
	INDIAN_ROSEWOOD,
	ALDER,
	WOODMAX
};

class GuitarSpec {
private:
	string model;
	Builder builder;
	Type type;
	Wood backWood, topWood;
public:
	GuitarSpec();
	GuitarSpec(Builder builder, string model, Type type, Wood backWood, Wood topWood);
	string getModel() { return model; }
	Builder getBuilder() { return builder; }
	Type getType() { return type; }
	Wood getBackWood() { return backWood; }
	Wood getTopWood() { return topWood; }
};


class Guitar{
private:
    string serialNumber;
    double price;
	GuitarSpec spec;
public:
	Guitar();
    Guitar(string serialNumber, double price, GuitarSpec spec);
	string getSerialNumber() { return serialNumber; }
	double getPrice() { return price; }
	GuitarSpec* getSpec() {	return &this->spec; } // NOTE:using call by reference to give address, the string data(model) won't be got by call by value 
};

string toLowerCase(string str);
string Type2String(Type type);
string Builder2String(Builder builder);
string Wood2String(Wood wood);