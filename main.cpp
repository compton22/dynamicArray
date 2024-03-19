#include "dynamicArray.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
//    clock_t start, duration;
//
//    const unsigned numOfArrays = 100000; // Number of dynamicArray objects
//    dynamicArray* arrays[numOfArrays];
//
//    // Tworzymy 10 000 tablic o pojemności 4
//    for (int i = 0; i < numOfArrays; ++i) {
//        arrays[i] = new dynamicArray(4);
//    }
//
//    for(int k = 0; k < 10; k++) {
//        start = clock();
//        for(unsigned i = 0; i < numOfArrays; i++) {
//            arrays[i]->addBack(5);
//        }
//        duration = clock() - start;
//        double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
//        cout << "Time taken for adding elements to 10,000,000 dynamic arrays: " << durationInSeconds << " seconds" << endl;
//    }
//
//    for (int i = 0; i < numOfArrays; ++i) {
//        delete arrays[i];
//    }
    dynamicArray arr(4);
    arr.addBack(0);
    arr.addBack(1);
    arr.addBack(2);
    arr.addBack(3);
    //arr.add(2, 9);

    arr.displayDynamicArray();
    arr.displayDynamicArrayWCapacity();

    return 0;
}
