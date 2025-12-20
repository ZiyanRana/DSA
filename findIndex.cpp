#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& array, int search) {
    for (int i = 0; i < array.size(); i++) {
        if (array[i] == search) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size, search;
    cout << "Enter the array size: ";
    cin >> size;

    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        cout << "Enter array element " << i + 1 << " : ";
        cin >> array[i];
    }

    cout << "\nEnter the element to be searched: ";
    cin >> search;

    int result = linearSearch(array, search);

    if (result != -1) {
        cout << "Element found at index: " << result;
    } else {
        cout << "Element not found.";
    }

    return 0;
}
