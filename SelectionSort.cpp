#include <iostream>
#include <vector>
using namespace std;

void displayOriginalArray(const vector<int>& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort ( vector<int>& array, int start, int end) {
    for (int i = start; i <= end-1 ; i++)
    {
        int minIndex = i;
        for ( int j = i+1 ; j <= end ; j++ )
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j ;
            }
        }
        if ( minIndex != i){
            swap(array[minIndex], array[i]);
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
    displayOriginalArray(array, size); 

    selectionSort (array, 0, size);

    cout << "Sorted array: ";
    displayOriginalArray(array, size);

    return 0;
}