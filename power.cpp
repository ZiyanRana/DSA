#include <iostream>
using namespace std;

int calculatePower (int num, int power)
{
   if (power == 1){
    return num;
   }
   else {
    return num * calculatePower (num, power-1) ;
   }
}

int main()
{
    int num = 2, power = 5;
    int value = calculatePower (num, power) ;
    cout << "Answer: " << value ;
    return 0;
}