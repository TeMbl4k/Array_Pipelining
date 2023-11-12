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

void Operation(double array[], int* temp[], void (*funcPtrs[6]) (double* array, int, int), int num, int array_size) {
    for (int i = 0; i < num; i++) {
        cout << "operation #" << i + 1 << "... ";
        switch (temp[i][0]) {
            case 5:
                funcPtrs[0](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            case 8:
                funcPtrs[1](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            case 20:
                funcPtrs[2](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            case 47:
                funcPtrs[3](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            case 500:
                funcPtrs[4](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            case 777:
                funcPtrs[5](array, array_size, temp[i][1]);
                cout << "completed" << endl;
                break;
            default:
                cout << "skipped" << endl;
                temp[i][2] = 0;
        }

        if (temp[i][2] == 1)   {
            cout << "Temp data: " << endl;
            for (int i = 0; i < array_size; i++) {
                cout << i + 1 << ") ";
                cout << fixed << setprecision(3) << array[i] << endl;
            }
        }
    }
}


void main(){
    int array_size, num_of_operations;
    const int values = 3;

    void (*funcPtrs[6]) (double* array, int, int);
    funcPtrs[0] = multiplyArray;
    funcPtrs[1] = addValueToAll;
    funcPtrs[2] = powerArray;
    funcPtrs[3] = OneToMultiples;
    funcPtrs[4] = changeSignFromIndex;
    funcPtrs[5] = divideElementAtIndex;

    cout << "Enter array size: ";
    cin >> array_size;

    double* array = new double[array_size]; // создаём массив чисел

    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cin >> array[i];
    }

    cout << "Enter number of operations: ";
    cin >> num_of_operations;

    int** operations = new int* [num_of_operations]; // создаём массив, который сохраняет введённые значения для каждой операции

    for (int i = 0; i < num_of_operations; ++i) {
        operations[i] = new int[values];
    }

    for (int i = 0; i < num_of_operations; ++i) {
        char print;
        cout << "(code \\ param \\ print ? ) " << i + 1 << ") ";
        cin >> operations[i][0]; // Операция
        cin >> operations[i][1]; // параметр
        cin >> print;
        if (print == '+')
            operations[i][2] = 1; // печатаем
        else
            operations[i][2] = 0; // не печатаем
     }

    cout << "Processing..." << endl;
    Operation(array, operations, funcPtrs, num_of_operations, array_size);

    cout << "-Result-" << endl;
    for (int i = 0; i < array_size; i++) {
        cout << i + 1 << ") ";
        cout << fixed << setprecision(3) << array[i] << endl;
    }

}