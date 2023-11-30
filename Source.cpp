#include <iostream>

#include "Plate.h"
#include "algorithm.h"


#define NUMBER_PLATE_PARAMETER 3

using namespace std;

void organizePlates(Plate plateList[], int numberPlates);

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
    
    int price = algorithm(plateList, plateWidth, plateLength);

    cout << price;

    /*
    for (int i = 0; i < numberPlates; i++) {
        plateList[i].printPlate();
    }
    */ 
   
    return 0;
}

int comparePlate(const void* p1, const void* p2) {
    Plate a = *(Plate*) p1;
    Plate b = *(Plate*) p2;
    return (b.getPrice() - a.getPrice());
}

void organizePlates(Plate plateList[], int numberPlates) {
    qsort(plateList, numberPlates, sizeof(Plate), comparePlate);
}