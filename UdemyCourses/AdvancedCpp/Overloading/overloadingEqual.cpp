#include <iostream>
#include "Complex.h"

using namespace std;

int main(){
    Complex c1(3,2);
    Complex c2(3,2);

    if(c1==c2){
        cout << "Equal!"<< endl;
    }
    else{
        cout << "Not Equal:(" <<endl;
    }

    if(c1!=c2){
        cout << "Not Equal... :(" <<endl;
    }
    else{
        cout << "Equal..." << endl;
    }

    return 0;
}