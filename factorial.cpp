#include <iostream>
using namespace std;

int calcFactorial (int num){
    if (num == 0 || num == 1) {
        return num;
    }
    else if (num < 0){
        cout << "Invalid.";
    }
    else {
        return num * calcFactorial (num-1);
    }
}

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num ;
    int factorial = calcFactorial(num);
    cout << "Factorial: " << factorial;
    return 0 ;
}