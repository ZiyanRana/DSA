#include <iostream>
#include <vector>
using namespace std;

void displayArray(const vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& array, int start, int end) {
    for (int i = start; i <= end - 1; i++) {
        for (int j = start; j <= end - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter the array size: ";
    cin >> size;
    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter array element " << i + 1 << ": ";
        cin >> array[i];
    }

    cout << "\nOriginal array: ";
    displayArray(array, size); 

    bubbleSort(array, 0, size - 1);

    cout << "Sorted array: ";
    displayArray(array, size);

    return 0;
}
