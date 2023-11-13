#include <iostream>
#include <cmath>
#include <iomanip>

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

void Operation(double array[], int operations[], int params[], bool print_codes[], void (*funcPtrs[6]) (double* array, int, int), int num, int array_size) {
    for (int i = 0; i < num; i++) {
        cout << "operation #" << i + 1 << "... ";
        switch (operations[i]) {
            case 5:
                multiplyArray(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            case 8:
                addValueToAll(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            case 20:
                powerArray(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            case 47:
                OneToMultiples(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            case 500:
                changeSignFromIndex(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            case 777:
                divideElementAtIndex(array, array_size, params[i]);
                cout << "completed" << endl;
                break;
            default:
                cout << "skipped" << endl;
                print_codes[i] = 0;
        }

        if (print_codes[i] == 1)   {
            cout << "params data: " << endl;
            for (int i = 0; i < array_size; i++) {
                cout << i + 1 << ") ";
                cout << fixed << setprecision(3) << array[i] << endl;
            }
        }
    }
}


void main(){
    int array_size, num_of_operations;
    char print;

    void (*funcPtrs[6]) (double* array, int, int) = { multiplyArray, addValueToAll, powerArray, OneToMultiples, changeSignFromIndex, divideElementAtIndex };
    
    cout << "Enter array size: ";
    cin >> array_size;

    double* array = new double[array_size]; // создаём массив чисел

    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cin >> array[i];
    }

    cout << "Enter number of operations: ";
    cin >> num_of_operations;

    int* operations = new int[num_of_operations];
    int* params = new int[num_of_operations];
    bool* print_codes = new bool[num_of_operations];

    for (int i = 0; i < num_of_operations; ++i) {
        cout << "(code \\ param \\ print ? ) " << i + 1 << ") ";
        cin >> operations[i];
        cin >> params[i];
        cin >> print;
        if (print == '+')
            print_codes[i] = true;
        else 
            print_codes[i] = false;
    }

    cout << "Processing..." << endl;
    Operation(array, operations, params, print_codes, funcPtrs, num_of_operations, array_size);

    cout << "-Result-" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cout << fixed << setprecision(3) << array[i] << endl;
    }

    delete[] array;
    delete[] operations;
    delete[] params;
    delete[] print_codes;
}