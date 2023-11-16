#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void multiplyArray(double array[], int size, int multiplier) {
    for (int i = 0; i < size; ++i) {
        array[i] *= multiplier;
    }
}

void addValueToAll(double array[], int size, int index) {
    if ((index >= 0) && (index < size)) {
        int valueToAdd = array[index];

        for (int i = 0; i < size; ++i) {
            array[i] += valueToAdd;
        }
    }
}

void powerArray(double array[], int size, int exponent) {
    for (int i = 0; i < size; ++i) {
        array[i] = pow(array[i], exponent);
    }
}

void OneToMultiples(double* arr, int par, int size) {
    for (int i = 0; i < size; i += par)
        arr[i] = 1;
}

void changeSignFromIndex(double array[], int size, int index) {
    for (int i = index; i < size; ++i) {
        array[i] = -array[i];
    }
}

void divideElementAtIndex(double array[], int size, int index) {
    if (index >= 0 && index < size) {
        array[index] /= 2;
    }
}

void printArray(double array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") " << fixed << setprecision(3) << array[i] << endl;
    }
}

void (*Operation_array(int num)) (double*, int, int) {
    switch (num) {
    case 5:
        return multiplyArray;
    case 8:
        return addValueToAll;
    case 20:
        return powerArray;
    case 47:
        return OneToMultiples;
    case 500:
        return changeSignFromIndex;
    case 777:
        return divideElementAtIndex;
    default:
        return nullptr;
    }
}

void processArray(double array[], int array_size, int num_of_operations, int params[], bool print_codes[], void (**selectedfuncPtrs) (double*, int, int)) {
    for (int i = 0; i < num_of_operations; i++) {
        cout << "operation #" << i + 1 << "... ";
        if (selectedfuncPtrs[i] != nullptr) {
            selectedfuncPtrs[i](array, array_size, params[i]);
            cout << "completed" << endl;

            if (print_codes[i]) {
                cout << "Temp data:" << endl;
                printArray(array, array_size);
            }
        }
        else {
            cout << "skipped" << endl;
        }
    }
}

int main() {
    int array_size, num_of_operations;

    cout << "Enter array size: ";
    cin >> array_size;

    double* array = new double[array_size];

    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cin >> array[i];
    }

    cout << "Enter number of operations: ";
    cin >> num_of_operations;

    int* params = new int[num_of_operations];
    bool* print_codes = new bool[num_of_operations];
    void(**selectedfuncPtrs)(double*, int, int) = new (void(*[num_of_operations])(double*, int, int));

    for (int i = 0; i < num_of_operations; ++i) {
        int num_of_operation;
        char print;

        cout << "(code \\ param \\ print ? ) " << i + 1 << ") ";
        cin >> num_of_operation >> params[i] >> print;
        print_codes[i] = (print == '+');

        selectedfuncPtrs[i] = Operation_array(num_of_operation);
    }

    cout << "Processing..." << endl;
    processArray(array, array_size, num_of_operations, params, print_codes, selectedfuncPtrs);

    cout << "-Result-" << endl;
    printArray(array, array_size);

    delete[] array;
    delete[] params;
    delete[] print_codes;

    return 0;
}
