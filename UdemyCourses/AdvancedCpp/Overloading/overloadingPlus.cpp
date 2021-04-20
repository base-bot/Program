#include <iostream> 
#include "Complex.h"

using namespace std;

int main() {
    Complex c1(3,4);
    Complex c2(2,3);
    Complex c3 = c1+c2;

    cout << c1 << endl;
    cout << c1+c2 << endl;
    cout << c1+c2+c3 << endl;
    
    Complex c4 (4,2);
    Complex c5 = c4 + 7;
    cout << c5 << endl;
    

    Complex c6(1,7);
    cout << 3.2 + c6 << endl; //with the first +operator overloading, one cannot solve this equation 
                                // since we defined the double number to be after the defined Complex variable. 
                                // This is why we ad to defined another summation operator
    return 0;
}