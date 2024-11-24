#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void CreateRandomArray(double* a, int numberOfElements, int start, int end, int i = 0) {
    if (i < numberOfElements) {
        a[i] = start + rand() % (end - start + 1);
        CreateRandomArray(a, numberOfElements, start, end, i + 1);
    }
}

void PrintArrayAsRow(double* a, int size, int i = 0) {
    if (i < size) {
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
        PrintArrayAsRow(a, size, i + 1);
    }
}

int FindC(double* arr, int size, int C, int index = 0, int counter = 0) {
    if (index == size) return counter;

    if (arr[index] > C) {
        counter++;
    }
    return FindC(arr, size, C, index + 1, counter);
}

int FindMaxAbsIndex(double* arr, int size, int index = 0, double maxAbs = 0, int maxAbsIndex = 0) {
    if (index == size) {
        return maxAbsIndex;
    }

    if (abs(arr[index]) > maxAbs) {
        maxAbs = abs(arr[index]);
        maxAbsIndex = index;
    }
    return FindMaxAbsIndex(arr, size, index + 1, maxAbs, maxAbsIndex);
}

double FindElementsProductAfterMaxAbs(double* arr, int size, int index, double product = 1.0) {
    if (index + 1 == size) {
        return product;
    }

    product *= arr[index + 1];
    return FindElementsProductAfterMaxAbs(arr, size, index + 1, product);
}

int CountNegativeElements(double* arr, int size, int index = 0, int count = 0) {
    if (index == size) {
        return count;
    }

    if (arr[index] < 0) {
        count++;
    }
    return CountNegativeElements(arr, size, index + 1, count);
}

void TransformArray(double* arr, double* arrCopy, int size, int positiveIndex, int index = 0, int negativeIndex = 0) {
    if (index == size) {
        return;
    }

    if (arr[index] < 0) {
        arrCopy[negativeIndex++] = arr[index];
    }
    else {
        arrCopy[positiveIndex++] = arr[index];
    }
    TransformArray(arr, arrCopy, size, positiveIndex, index + 1, negativeIndex);
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter size: ";
    cin >> n;

    double* dynamicArray = new double[n];
    double C = 0.0;

    cout << "Enter C: ";
    cin >> C;

    cout << "Create Array" << endl;
    CreateRandomArray(dynamicArray, n, -10, 10);

    cout << "Original array:" << endl;
    PrintArrayAsRow(dynamicArray, n);

    int c = FindC(dynamicArray, n, C);
    cout << "Number of elements greater than C: " << c << endl;

    cout << "Find Max Abs Index" << endl;
    int maxAbsIndex = FindMaxAbsIndex(dynamicArray, n);
    cout << "after max abs: " << FindElementsProductAfterMaxAbs(dynamicArray, n, maxAbsIndex) << endl;

    double* fsArray = new double[n];
    int negativeCount = CountNegativeElements(dynamicArray, n);

    TransformArray(dynamicArray, fsArray, n, negativeCount);

    cout << "Sorted array:" << endl;
    PrintArrayAsRow(fsArray, n);

    delete[] dynamicArray;
    delete[] fsArray;
    return 0;
}
