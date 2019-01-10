#include "guitar.hpp"

Guitar::Guitar()
{
}

Guitar::Guitar(string serialNumber, double price, string builder, string model, string type, string backWood, string topWood){
    this->serialNumber.append(serialNumber);
    this->price = price;
    this->builder.append(builder);
    this->model.append(model);
    this->type.append(type);
    this->backWood.append(backWood);
    this->topWood.append(topWood);
}