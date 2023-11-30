#include "Plate.h"

int algorithm(Plate plateList[], int numberPlates, int width, int length);
int verticalCut(int width, int length, int cut, Plate plateList[], int numberPlates);
int horizontalCut(int plate[2], Plate plateList[], int cut, int numberPlates);