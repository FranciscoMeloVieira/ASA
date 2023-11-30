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

double Plate::getProfit() {
    return ((length * width) / price);
}

/*
void Plate::printPlate() {
    std::cout << this->length << this->width << this->price;
}
*/


