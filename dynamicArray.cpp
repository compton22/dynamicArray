GOOWNO
#include "dynamicArray.h"

dynamicArray::dynamicArray(int capacity) : dynamicArrayCapacity(capacity), dynamicArrayPtr(new int[capacity]) {
    //konstruktor z argumentem rozmiaru tablicy, pointer wskazuje na początek tej tablicy
    for(int i = 0; i < dynamicArrayCapacity; i++) {
        dynamicArrayPtr[i] = NULL;
    }
}
dynamicArray::dynamicArray() : dynamicArraySize(0), dynamicArrayCapacity(0), dynamicArrayPtr(new int[0])
{
    //konstruktor domyślny
}
dynamicArray::~dynamicArray() {
    if (dynamicArrayPtr == NULL) return;
    free(dynamicArrayPtr);
    dynamicArrayCapacity = 0;
    dynamicArraySize = 0;
    dynamicArrayPtr = NULL;
}

void dynamicArray::increaseCapacity() {
    // Sprawdzamy, czy tablica ma wystarczającą pojemność
    if (dynamicArraySize == dynamicArrayCapacity) {
        // Zwiększamy pojemność dwukrotnie (capacity = 2 * size)
        dynamicArrayCapacity *= 2;

        // Tworzymy nowy bufor o zwiększonej pojemności
        int* buffer = new int[dynamicArrayCapacity];

        // Kopiujemy istniejące elementy do nowego bufora
        for (int i = 0; i < dynamicArraySize+1; i++) {
            buffer[i] = dynamicArrayPtr[i];
        }

        // Usuwamy stary bufor
        delete[] dynamicArrayPtr;

        // Przypisujemy nowy bufor do dynamicArrayPtr
        dynamicArrayPtr = buffer;
    }
}

void dynamicArray::decreaseCapacity() {
    // Sprawdzamy, czy liczba elementów w tablicy spadła poniżej połowy jej aktualnej pojemności
    if (dynamicArraySize == (dynamicArrayCapacity / 2)) {

        // Tworzymy nowy bufor o zmniejszonej pojemności
        int* buffer = new int[dynamicArrayCapacity/2];

        // Kopiujemy istniejące elementy do nowego bufora
        for (int i = 0; i < dynamicArraySize+1; ++i) {
            buffer[i] = dynamicArrayPtr[i];
        }

        // Usuwamy stary bufor
        delete[] dynamicArrayPtr;

        // Przypisujemy nowy bufor do dynamicArrayPtr
        dynamicArrayPtr = buffer;
        dynamicArrayCapacity /= 2;
    }
}


int dynamicArray::getDynamicArraySize() {
    return dynamicArraySize;
}

bool dynamicArray::isDynamicArrayEmpty() {
    return dynamicArraySize == 0;
}

int dynamicArray::getDynamicArrayElementAt(int index) {
    if (index < 0 || index >= dynamicArraySize) {
        cout << "Błąd: Indeks poza zakresem!" << endl;
        exit(EXIT_FAILURE);
    }
    return dynamicArrayPtr[index];
}

void dynamicArray::displayDynamicArrayWCapacity() {
    for(int i = 1; i < dynamicArrayCapacity+1; i++) {
        cout << dynamicArrayPtr[i] << "\t"; // Wyświetlamy wartość na pozycji i
    }
    cout << endl;
}

void dynamicArray::displayDynamicArray() {  //wyswietlenie tablicy
    // Przechodzimy przez tablicę i wyświetlamy jej zawartość
    for(int i = 1; i < dynamicArraySize+1; i++) {
        cout << dynamicArrayPtr[i] << "\t"; // Wyświetlamy wartość na pozycji i
    }
    cout << endl;
}

void dynamicArray::addBack(int element) { // dodaje element w koniec tablicy
    increaseCapacity();
    dynamicArraySize++;
    dynamicArrayPtr[dynamicArraySize] = element;
}

void dynamicArray::add(int index, int element) {
    if (index < 0) {
        cout << "Błąd: Niepoprawny indeks!" << endl;
        return;
    }

    if(index < dynamicArraySize) {
        increaseCapacity();
        dynamicArraySize++;
        for (int i = dynamicArraySize; i > index; i--) {
            dynamicArrayPtr[i+1] = dynamicArrayPtr[i];
        }
        dynamicArrayPtr[index+1] = element;
    }else{
        //gdy index jest większy niż size, wstaw nowy element na pierwszą wolną pozycję
        increaseCapacity();
        addBack(element);
    }
}

void dynamicArray::remove(int index) {
    if (index < 0 || index > dynamicArraySize) {
        cout << "Błąd: Niepoprawny indeks!" << endl;
        return;
    }

    // Usuwamy element na podanym indeksie
    for (int i = index+1; i < dynamicArraySize; ++i) {
        dynamicArrayPtr[i] = dynamicArrayPtr[i + 1];
    }
    dynamicArraySize--;

    decreaseCapacity();
}

void dynamicArray::removeBack() {
    dynamicArraySize--;
    decreaseCapacity();
}

void dynamicArray::addFront(int element) {
    increaseCapacity();
    dynamicArraySize++;
    for (int i = dynamicArraySize; i > 0; i--) {
        dynamicArrayPtr[i] = dynamicArrayPtr[i-1];
    }
    dynamicArrayPtr[1] = element;
}

void dynamicArray::removeFront() {
    for (int i = 1; i < dynamicArraySize; i++) {
        dynamicArrayPtr[i] = dynamicArrayPtr[i+1];
    }
    dynamicArraySize--;
    decreaseCapacity();
}