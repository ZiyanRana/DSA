#include <iostream>
#include <vector>
using namespace std;

void displayOriginalArray(const vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void mergeSort ( vector<int>& array, int start, int end) {
    
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

    mergeSort (array, 0, size);

    cout << "Sorted array: ";
    displayOriginalArray(array, size);

    return 0;
}