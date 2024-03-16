#include <iostream>
#include "dynamicArray.h"

using namespace std;

int main() {
    dynamicArray arr(4);

    arr.add(0, 5);
    arr.add(1, 8);
    arr.add(2,3);
    arr.add(3, 11);
    arr.add(4,21);
    arr.add(2,7);
    arr.remove(2);
    arr.addBack(56);
    arr.addBack(56);
    arr.addBack(56);
    arr.addBack(56);
    arr.addBack(56);
    arr.remove(9);
    arr.removeBack();


    cout << arr.getDynamicArraySize();
    cout << endl;
    arr.displayDynamicArrayWCapacity();
    cout << endl;
    arr.displayDynamicArray();
//    arr.add(1,2);
//    cout << arr.getDynamicArraySize() << endl;
//    arr.displayDynamicArray();
//    arr.add(2,4);
//    arr.add(0,7);
}
