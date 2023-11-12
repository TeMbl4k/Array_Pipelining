#include <iostream>
#include <cmath>

using namespace std;

void multiplyArray(double array[], int size, int multiplier) { // 5
    for (int i = 0; i < size; ++i) {
        array[i] *= multiplier;
    }
}

void addValueToAll(double array[], int size, int index) { // 8
    if ((index >= 0) && (index < size)) {
        int valueToAdd = array[index];

        for (int i = 0; i < size; ++i) {
            array[i] += valueToAdd;
        }
    }
}

void powerArray(double array[], int size, int exponent) { // 20
    for (int i = 0; i < size; ++i) {
        array[i] = pow(array[i], exponent);
    }
}

void OneToMultiples(double array[], int size, int divisor) { // 47
    for (int i = 0; i < size; ++i) {
        if (i % divisor == 0) {
            array[i] = 1;
        }
    }
}

void changeSignFromIndex(double array[], int size, int index) { // 500
    for (int i = index; i < size; ++i) {
        array[i] = -array[i];
    }
}

void divideElementAtIndex(double array[], int size, int index) { // 777
    if (index >= 0 && index < size) {
        array[index] /= 2;
    }
}

void Operations(double array[], void (*funcPtrs[6]) (double* array, int, int), int num, ) {
    for (int i = 0; i < num; i++) {
        cout << "(code \ param \ print ? ) " << i + 1 << ") ";
        cin >> code, param, print
    }
}


void main(){
    int array_size, num_of_operations;

    void (*funcPtrs[6]) (double* array, int, int);
    funcPtrs[5] = multiplyArray;
    funcPtrs[8] = addValueToAll;
    funcPtrs[20] = powerArray;
    funcPtrs[47] = OneToMultiples;
    funcPtrs[500] = changeSignFromIndex;
    funcPtrs[777] = divideElementAtIndex;

    cout << "Enter array size: ";
    cin >> array_size;

    double* array = new double[array_size];

    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cin >> array[i];
    }

    cout << "Enter number of operations: ";
    cin >> num_of_operations;


}