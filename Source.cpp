#include <iostream>

#include "Plate.h"


#define NUMBER_PLATE_PARAMETER 3

using namespace std;

void organizePlates(Plate plateList[], int numberPlates);

int comparePlate(Plate p1, Plate p2);

int main() {

    int plateWidth, plateLength, numberPlates;

    cin >> plateWidth >> plateLength;
    cin >> numberPlates;

    Plate plateList[numberPlates];
    
    for (int i = 0; i < numberPlates; i++) {
        int length, width, price;

        cin >> length >> width >> price;

        Plate newPlate(length, width, price);
        plateList[i] = newPlate;
        
    }

    organizePlates(plateList, numberPlates);

    /*
    for (int i = 0; i < numberPlates; i++) {
        plateList[i].printPlate();
    }
    */ 
   
    return 0;
}

int comparePlate(Plate p1, Plate p2) {
    return (p1.getPrice - p2.getPrice);
}

void organizePlates(Plate plateList[], int numberPlates) {
    qsort(*plateList, numberPlates, sizeof(Plate), comparePlate);
}