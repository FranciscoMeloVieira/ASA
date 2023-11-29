#include <iostream>


#define NUMBER_PLATE_PARAMETER 3

using namespace std;


int main() {

    int plateWidth, plateLength, numberPlates;

    cin >> plateWidth >> plateLength;
    cin >> numberPlates;

    int plates[numberPlates][NUMBER_PLATE_PARAMETER];

    for (int i = 0; i < numberPlates; i++) {
        cin >> plates[i][0] >> plates[i][1] >> plates[i][2];
    }

    organizePlates(plates);

    return 0;
}


void organizePlates(int **plates) {

}