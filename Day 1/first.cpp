#include <iostream>
using namespace std;

int getElementsNumber()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    return n;
}
int* getArray( int n )
{
    int* array = new int[n] ;
    for (int i=0; i<n ; i++){
        cout << "Enter element number " << i+1 << ": ";
        cin >> array[i];
    }
    return array ;
}
int getMax( int* array , int n )
{
    int max = 0;
    for (int i=0 ; i<n ; i++ ){
        if (array[i] > max) { max = array[i];}
    }
    return max;
}
int getMin( int* array, int n )
{
    int min = array[0];
    for (int i=0 ; i<n ; i++ ){
        if (array[i] < min) { min = array[i];}
    }
    return min;
}

int main()
{
    int n = getElementsNumber();
    int* array = getArray(n);
    
    int max = getMax( array, n ), min = getMin( array, n ); 
    
    cout << "\nMaximum element is: " << max << "\nMinimum element is: " << min << endl ;
    delete[] array;
    return 0;
}