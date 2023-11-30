#include <iostream>

#include "Plate.h"


#define NUMBER_PLATE_PARAMETER 3

using namespace std;

void organizePlates(Plate plateList[]);

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

    organizePlates(plateList);

    /*
    for (int i = 0; i < numberPlates; i++) {
        plateList[i].printPlate();
    }
    */ 
   
    return 0;
}


void organizePlates(Plate plateList[]) {

}