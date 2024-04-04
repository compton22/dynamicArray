#include "dynamicArray.h"
#include "Zapis.h"
#include "test.h"
#include "cstdlib"
#include <ctime>
#include <chrono>

using namespace std;

void runDynamicArray() {
    dynamicArray dynamicArray1(4);
    int element, index;
    char choice2;
    do {
        cout << "1. addFront" << endl;
        cout << "2. addBack" << endl;
        cout << "3. add" << endl;
        cout << "4. removeFront" << endl;
        cout << "5. removeBack" << endl;
        cout << "6. remove" << endl;
        cout << "7. display" << endl;
        cout << "8. display with capacity" << endl;
        cout << "9. isDynamicArrayEmpty" << endl;
        cout << "10. getDynamicArrayElementAt" << endl;
        cout << "11. getDynamicArraySize" << endl;
        cout << "12. fillFromArrayCSV" << endl;
        cout << "13. Exit" << endl;

        cin >> choice2;
        switch (choice2) {
            case '1':
                cout << "Enter the element you want to add: ";
                cin >> element;
                dynamicArray1.addFront(element);
                break;
            case '2':
                cout << "Enter the element you want to add (back): ";
                cin >> element;
                dynamicArray1.addBack(element);
                break;
            case '3':
                cout << "Enter the index and the element you want to add: ";
                cin >> index >> element;
                dynamicArray1.add(index, element);
                break;
            case '4':
                cout << "Removing the first element..." << endl;
                dynamicArray1.removeFront();
                break;
            case '5':
                cout << "Removing the last element..." << endl;
                dynamicArray1.removeBack();
                break;
            case '6':
                cout << "Enter the index you want to remove: ";
                cin >> index;
                dynamicArray1.remove(index);
                break;
            case '7':
                dynamicArray1.displayDynamicArray();
                break;
            case '8':
                dynamicArray1.displayDynamicArrayWCapacity();
                break;
            case '9':
                if (dynamicArray1.isDynamicArrayEmpty()) {
                    cout << "The dynamicArray is empty." << endl;
                } else {
                    cout << "The dynamicArray is not empty." << endl;
                }
                break;
            case '10':
                cout << "Enter the index of the element you want to get: ";
                cin >> index;
                cout << "The element at index " << index << " is: " << dynamicArray1.getDynamicArrayElementAt(index)
                     << endl;
                break;
            case '11':
                cout << "The size of the dynamicArray is: " << dynamicArray1.getDynamicArraySize() << endl;
                break;
            case '12':
                cout << "Filling the dynamicArray from a CSV file: random_numbers.csv ..." << endl;
                dynamicArray1.fillFromArrayCSV("random_numbers.csv", 50000);
                break;
            case '13':
                cout << "Exiting..." << endl;
                break;

        }
    } while (choice2 != '13');
}

void testing(const unsigned numOfArrays, int size, int iteration){
    Zapis plik_addFront("ArrayList_addFront.csv");
    Zapis plik_addBack("ArrayList_addBack.csv");
    Zapis plik_add("ArrayList_add.csv");
    Zapis plik_removeFront("ArrayList_removeFront.csv");
    Zapis plik_removeBack("ArrayList_removeBack.csv");
    Zapis plik_remove("ArrayList_remove.csv");
    Zapis plik_find("ArrayList_find.csv");

    dynamicArray dynamicArray2(4);
    dynamicArray2.fillFromArrayCSV("random_numbersi.csv", 50000);

    cout << "Please wait..." << endl;
    dynamicArray *arrays[numOfArrays];
    dynamicArray *backupArrays[numOfArrays];

    // Tworzymy numOfArrays tablic o pojemności 4
    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i] = new dynamicArray(4);
        backupArrays[i] = new dynamicArray(4);
    }
    for (int i = 0; i < numOfArrays; i++) {
        arrays[i]->fillFromArrayCSV("random_numbers.csv", size);
        backupArrays[i]->fillFromArrayCSV("random_numbers.csv", size);
    }

    //cout << arrays[1]->getDynamicArraySize() << endl;

    //addFront
    auto begin = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->addFront(5);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //double durationInNanoSeconds = double(duration) / CLOCKS_PER_SEC;
    plik_addFront.shot(iteration, elapsed.count(), size);
    //addBack
    auto begin2 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->addBack(5);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    plik_addBack.shot(iteration, elapsed2.count(), size);

    //add
    int index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin3 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->add(index, 5);
    }
    auto end3 = std::chrono::high_resolution_clock::now();
    auto elapsed3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3);
    plik_add.shot(iteration, elapsed3.count(), size);

    //removeFront
    auto begin4 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeFront();
    }
    auto end4 = std::chrono::high_resolution_clock::now();
    auto elapsed4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4);
    plik_removeFront.shot(iteration, elapsed4.count(), size);

    //removeBack
    auto begin5 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->removeBack();
    }
    auto end5 = std::chrono::high_resolution_clock::now();
    auto elapsed5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5);
    plik_removeBack.shot(iteration, elapsed5.count(), size);

    //remove
    index = dynamicArray2.getDynamicArrayElementAt(0);
    auto begin6 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        arrays[i]->remove(index);
    }
    auto end6 = std::chrono::high_resolution_clock::now();
    auto elapsed6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end6 - begin6);
    plik_remove.shot(iteration, elapsed6.count(), size);

    //find
    auto begin7 = std::chrono::high_resolution_clock::now();
    for (unsigned i = 0; i < numOfArrays; i++) {
        int number = dynamicArray2.getDynamicArrayElementAt(i);
        arrays[i]->findElement(number);
    }
    auto end7 = std::chrono::high_resolution_clock::now();
    auto elapsed7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end7 - begin7);
    plik_find.shot(iteration, elapsed7.count(), size);


    for (int i = 0; i < numOfArrays; ++i) {
        delete arrays[i];
        delete backupArrays[i];
    }
}
void runTests(const unsigned numOfArrays) {

    test::generateRandomNumbers(80000, 0, 100000, "random_numbers.csv", 5);
    test::generateRandomNumbers(80000, 0, 60000, "random_numbersi.csv", 3);

    char choice3;
    do {
        cout << "1. array_10" << endl;
        cout << "2. array_100" << endl;
        cout << "3. array_1k" << endl;
        cout << "4. array_2k" << endl;
        cout << "5. array_4k" << endl;
        cout << "6. array_8k" << endl;
        cout << "7. array_16k" << endl;
        cout << "8. array_32k" << endl;
        cout << "9. array_64k" << endl;
        cout << "X. array_128k" << endl;
        cout << "A. Test all" << endl;
        cout << "0. Exit" << endl;



        cin >> choice3;
        switch (choice3) {
            case '0':
                cout << "Exiting..." << endl;
                break;
            case '1':
            {
                testing(numOfArrays, 10,1);
                break;
            }
            case '2':
            {
                testing(numOfArrays, 100, 2);
                break;
            }
            case '3':
            {
                testing(numOfArrays, 1000, 3);
                break;
            }
            case '4':
            {
                testing(numOfArrays, 2000, 4);
                break;
            }
            case '5':
            {
                testing(numOfArrays, 4000, 5);
                break;
            }
            case '6':
            {
                testing(numOfArrays, 8000, 6);
                break;
            }
            case '7':
            {
                testing(numOfArrays, 16000, 7);
                break;
            }
            case '8':
            {
                testing(numOfArrays, 32000, 8);
                break;
            }
            case '9':
            {
                testing(numOfArrays, 64000, 9);
                break;
            }
            case 'X':
            {
                testing(numOfArrays, 128000, 10);
                break;
            }
            case 'A':
            {
                testing(numOfArrays, 10, 1);
                testing(numOfArrays, 100, 2);
                testing(numOfArrays, 1000, 3);
                testing(numOfArrays, 2000, 4);
                testing(numOfArrays, 4000, 5);
                testing(numOfArrays, 8000, 6);
                testing(numOfArrays, 16000, 7);
                testing(numOfArrays, 32000, 8);
                testing(numOfArrays, 64000, 9);
                testing(numOfArrays, 128000, 10);
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice3 != '0');
}


int main() {
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Your dynamicArray" << endl;
        cout << "2. Tests" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch(choice) {
            case '1':
                runDynamicArray();
                break;
            case '2':
                cout << "Running tests..." << endl;
                cout << "Please choose the number of arrays, " << endl;
                int numOfArrays;
                cin >> numOfArrays;
                cout << "Please wait..." << endl;
                runTests(numOfArrays);
                break;
            case '3':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != '3');

    return 0;
}
