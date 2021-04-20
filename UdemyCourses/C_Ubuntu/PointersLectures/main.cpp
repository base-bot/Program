#include <iostream>

using namespace std;

int main(){
    int a = 50;
    int* ptr = &a;
    int** ptr2 = &ptr;

    *ptr = 25;

    cout << "a is now equal to:  " << a << ", and PTR is reference number is  " << ptr << ", and PTR2 is reference number is  " << ptr2 << endl;
    cout << "a is now equal to:  " << a << ", and PTR is reference number is  " << ptr << ", and PTR is reference number is  " << *ptr2 << endl;
    cout << "a is now equal to:  " << a << ", and PTR is reference number is  " << ptr << ", and PTR2 value is equal to  " << **ptr2 << endl;

    return 0;
}