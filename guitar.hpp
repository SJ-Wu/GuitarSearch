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

class Guitar{
private:
    string serialNumber, model;
	Builder builder;
	Type type;
	Wood backWood, topWood;
    double price;
public:
	Guitar();
    Guitar(string serialNumber, double price, Builder builder, string model, Type type, Wood backWood, Wood topWood);
	string getSerialNumber() { return serialNumber; }
	double getPrice() { return price; }
	Builder getBuilder() { return builder; }
	string getModel() { return model; }
	Type getType() { return type; }
	Wood getBackWood() { return backWood; }
	Wood getTopWood() { return topWood; }
};

string toLowerCase(string str);
string Type2String(Type type);
string Builder2String(Builder builder);
string Wood2String(Wood wood);