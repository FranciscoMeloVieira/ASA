#include "Plate.h"
#include <iostream>

Plate::Plate(){
    this->length = this->width = this->price = 0;
}

Plate::Plate(int length, int width, int price) {
    this->length = length;
    this->width = width;
    this->price = price;
}

int Plate::getPrice() {
    return (this->price);
}

int Plate::getWidth() {
    return (this->width);
}

int Plate::getLength() {
    return (this->length);
}

bool Plate::samePlate(int length, int width) {
    if ((this->length == length && this->width == width) || (this->length == width && this->width == length)) {
        return true;
    }
    else {
        return false;
    }
}
/*
void Plate::printPlate() {
    std::cout << this->length << this->width << this->price;
}
*/




