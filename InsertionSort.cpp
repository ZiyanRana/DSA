#include <iostream>
#include <vector>
using namespace std;

void displayOriginalArray(const vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(vector<int>& array, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= start && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    displayOriginalArray(array, size);

    insertionSort(array, 0, size - 1);

    cout << "Sorted array: ";
    displayOriginalArray(array, size);

    return 0;
}
