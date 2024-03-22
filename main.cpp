#include "dynamicArray.h"
#include "Zapis.h"
#include "test.h"

#include <ctime>

using namespace std;

void runTests(const unsigned numOfArrays, int j){
    clock_t start, duration;
    Zapis plik_addBack("ArrayList.csv");

    test::generateRandomNumbers(100, 0, 525, "random_numbers.csv", 5);

     // Number of dynamicArray objects
    dynamicArray* arrays[numOfArrays];

    // Tworzymy 10 000 tablic o pojemności 4
    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i] = new dynamicArray(4);
    }

    for (int i = 0; i < numOfArrays; ++i) {
        arrays[i]->fillFromArrayCSV("random_numbers.csv");
    }
    char choice1;
    cin >> choice1;

    for(int k = 0; k < j; k++) {       start = clock();
        for(unsigned i = 0; i < numOfArrays; i++) {
            arrays[i] -> addBack(5);
        }
        duration = clock() - start;
        double durationInSeconds = double(duration) / CLOCKS_PER_SEC;
        plik_addBack.shot(k, unsigned(duration), numOfArrays);
    }

    arrays[1] -> displayDynamicArray();

    for (int i = 0; i < numOfArrays; ++i) {
        delete arrays[i];
    }
}

int main() {
    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Your dynamicArray" << endl;
        cout << "2. Tests" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                break;
            case '2':
                runTests(10000, 10);
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
