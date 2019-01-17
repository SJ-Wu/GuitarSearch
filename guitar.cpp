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

GuitarSpec::GuitarSpec(Builder builder, string model, Type type, Wood backWood, Wood topWood)
{
	this->builder = builder;
	this->model.append(toLowerCase(model));
	this->type = type;
	this->backWood = backWood;
	this->topWood = topWood;
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

