#include "Plate.h"

int verticalCut(int width, int length, int cut, Plate plateList[], int numberPlates);

int horizontalCut(int plate[2], Plate plateList[], int cut, int numberPlates);

int algorithm(Plate plateList[], int numberPlates, int width, int length) {

    int price, verticalPrice;

    price = verticalPrice = 0;


    for (int i = 0; i <= length; i++) {
        verticalPrice =  verticalCut(width, length, i, plateList, numberPlates);
        
        if (verticalPrice > price) {
            price = verticalPrice;
        }
    }

    return (price);
}

int verticalCut(int width, int length, int cut, Plate plateList[], int numberPlates) {

    int smallPrice, bigPrice;
    int tempSmallPrice, tempBigPrice;

    int smallPlate[2], bigPlate[2];

    smallPrice = bigPrice = 0;
    tempSmallPrice = tempBigPrice = 0;

    smallPlate[0] = cut;
    bigPlate[0] = length - cut;
    smallPlate[1] = bigPlate[1] = width;

    for (int i = 0; i <= width; i++) {
        tempSmallPrice = horizontalCut(smallPlate, plateList, i, numberPlates);
        tempBigPrice = horizontalCut(bigPlate, plateList, i, numberPlates);

        if (tempSmallPrice >= smallPrice) {
            smallPrice = tempSmallPrice;
        }
        if (tempBigPrice >= bigPrice) {
            bigPrice = tempBigPrice;
        }
    }

    return (smallPrice + bigPrice);
}

int horizontalCut(int plate[2], Plate plateList[], int cut, int numberPlates) {

    int smallPrice, bigPrice;
    int smallPlate[2], bigPlate[2];

    smallPrice = bigPrice = 0;

    smallPlate[0] = bigPlate[0] = plate[0];
    smallPlate[1] = cut;
    bigPlate[1] = plate[1] - cut;

    for (int i = 0; i <= numberPlates; i++) {
        if ((plateList[i].getLength() == smallPlate[0] && plateList[i].getWidth() == smallPlate[1]) || 
        (plateList[i].getLength() == smallPlate[1] && plateList[i].getWidth() == smallPlate[0])) {
            smallPrice = plateList[i].getPrice() + algorithm(plateList, numberPlates, bigPlate[1], bigPlate[0]);
            break;
        }
    }

    for (int i = 0; i <= numberPlates; i++) {
        if ((plateList[i].getLength() == bigPlate[0] && plateList[i].getWidth() == bigPlate[1]) || 
        (plateList[i].getLength() == bigPlate[1] && plateList[i].getWidth() == bigPlate[0])) {
            bigPrice = plateList[i].getPrice() +  algorithm(plateList, numberPlates, smallPlate[1], smallPlate[0]);
            break;
        }
    }

    return (smallPrice + bigPrice);
    
}