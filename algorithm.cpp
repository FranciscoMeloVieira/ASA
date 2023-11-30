#include "Plate.h"

int verticalCut(int width, int length, int cut, Plate plateList[]);

int horizontalCut(int plate[2], Plate plateList[], int cut);

int algorithm(Plate plateList[], int width, int length) {

    int price, verticalPrice = 0;


    for (int i = 0; i <= length / 2; i++) {
        verticalPrice =  verticalCut(width, length, i, plateList);
        
        if (verticalPrice > price) {
            price = verticalPrice;
        }
    }

    return (price);
}

int verticalCut(int width, int length, int cut, Plate plateList[]) {

    int smallPrice, bigPrice = 0;
    int tempSmallPrice, tempBigPrice = 0;

    int smallPlate[2], bigPlate[2];

    smallPlate[0] = cut;
    bigPlate[0] = length - cut;
    smallPlate[1] = bigPlate[1] = width;

    for (int i = 0; i <= width / 2; i++) {
        tempSmallPrice = horizontalCut(smallPlate, plateList, i);
        tempBigPrice = horizontalCut(bigPlate, plateList, i);

        if (tempSmallPrice >= smallPrice) {
            smallPrice = tempSmallPrice;
        }
        if (tempBigPrice >= bigPrice) {
            bigPrice = tempBigPrice;
        }
    }

    return (smallPrice + bigPrice);
}

int horizontalCut(int plate[2], Plate plateList[], int cut) {

    int smallPrice, bigPrice = 0;
    int numberPlates = sizeof(plateList) / sizeof(Plate);

    int smallPlate[2], bigPlate[2];

    smallPlate[0] = bigPlate[0] = plate[0];
    smallPlate[1] = cut;
    bigPlate[1] = plate[1] - cut;

    for (int i = 0; i <= numberPlates; i++) {
        if ((plateList[i].getLength() == smallPlate[0] && plateList[i].getWidth() == smallPlate[1]) || 
        (plateList[i].getLength() == smallPlate[1] && plateList[i].getWidth() == smallPlate[0])) {
            smallPrice = plateList[i].getPrice();
            break;
        }
    }
    for (int i = 0; i <= numberPlates; i++) {
        if ((plateList[i].getLength() == bigPlate[0] && plateList[i].getWidth() == bigPlate[1]) || 
        (plateList[i].getLength() == bigPlate[1] && plateList[i].getWidth() == bigPlate[0])) {
            bigPrice = plateList[i].getPrice();
            break;
        }
    }

    return (smallPrice + bigPrice);
    
}