#include "Plate.h"
#include <stdio.h>

int verticalCut(int width, int length, int cut, Plate plateList[], int numberPlates);

int horizontalCut(int plate[2], Plate plateList[], int cut, int numberPlates);

int algorithm(Plate plateList[], int numberPlates, int width, int length) {

    int price, verticalPrice;

    price = verticalPrice = 0;

    if (width <= 0 || length <= 0) {
        return (price);
    }


    for (int i = 0; i <= length / 2; i++) {
        verticalPrice =  verticalCut(width, length, i, plateList, numberPlates);
        
        if (verticalPrice > price) {
            price = verticalPrice;
        }
    }
    //printf("fim algoritmo\n");
    return (price);
}

int verticalCut(int width, int length, int cut, Plate plateList[], int numberPlates) {

    int smallPrice, bigPrice;
    int tempSmallPrice, tempBigPrice;

    printf("%d cut vertical\n", cut);

    int smallPlate[2], bigPlate[2];

    smallPrice = bigPrice = 0;
    tempSmallPrice = tempBigPrice = 0;

    smallPlate[0] = cut;
    bigPlate[0] = length - cut;
    smallPlate[1] = bigPlate[1] = width;
    //printf("%d width\n", width);
    
    for (int i = 0; i <= width / 2; i++) {
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

    int smallPlate[2], bigPlate[2];
    int price;

    smallPlate[0] = bigPlate[0] = plate[0];
    smallPlate[1] = cut;
    bigPlate[1] = plate[1] - cut;

    price = 0;

    for (int i = 0; i <= numberPlates; i++) {
        if (plateList[i].samePlate(smallPlate[0],smallPlate[1])) {
            price += plateList[i].getPrice();
            break;
        }
    }
    for (int i = 0; i <= numberPlates; i++) {
        if (plateList[i].samePlate(bigPlate[0],bigPlate[1])) {
        price += plateList[i].getPrice();
        break;
        }
    }

    if (bigPlate[0] > 0 && bigPlate[1] > 0) {
        price += algorithm(plateList, numberPlates, bigPlate[1], bigPlate[0]);
    }

    return (price);
}