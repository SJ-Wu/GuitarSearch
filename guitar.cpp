#include "guitar.hpp"

Guitar::Guitar()
{
}

Guitar::Guitar(string serialNumber, double price, GuitarSpec spec) {
	this->serialNumber.append(toLowerCase(serialNumber));
    this->price = price;
	this->spec = spec;
}

GuitarSpec::GuitarSpec()
{
}

GuitarSpec::GuitarSpec(Builder builder, string model, Type type, Wood backWood, Wood topWood, int numStrings)
{
	this->builder = builder;
	this->model.append(toLowerCase(model));
	this->type = type;
	this->backWood = backWood;
	this->topWood = topWood;
	this->numStrings = numStrings;
}

bool GuitarSpec::matches(GuitarSpec spec)
{
	Builder builder = spec.getBuilder();
	if (builder == this->getBuilder()) {
		string model = toLowerCase(spec.getModel());
		if (model == this->getModel()) {
			Type type = spec.getType();
			if (type == this->getType()) {
				Wood backWood = spec.getBackWood();
				if (backWood == this->getBackWood()) {
					Wood topWood = spec.getTopWood();
					if (topWood == this->getTopWood()) {
						int numStrings = spec.getNumStrings();
						if (numStrings == this->getNumStrings()){
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


string toLowerCase(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

string Type2String(Type type) {
	switch (type) {
	case ACOUSTIC:
		return "Acoustic";
		break;
	case ELECTRIC:
		return "Electric";
		break;
	default:
		return "Unexpected error";
	}
}

string Builder2String(Builder builder) {
	switch (builder) {
	case FENDER:
		return "Fender";
		break;
	case MARTIN:
		return "Martin";
		break;
	default:
		return "Unexpected error";
	}
}

string Wood2String(Wood wood) {
	switch (wood) {
	case INDIAN_ROSEWOOD:
		return "Indian Rosewood";
		break;
	case ALDER:
		return "Alder";
		break;
	default:
		return "Unexpected error";
	}
}

