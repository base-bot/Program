#include <iostream>

using namespace std;

int main(){
    int x = 2;
    switch(x)
    {
        case 0: cout << "CASE ZERO" << endl;
        break;

        case 1: cout << "CASE ONE" << endl;
        break;

        case 2:

        case 3: cout << "CASE TWO OR THREE" << endl;
        break;

        default: cout << "NO CASES DEFINED" << endl;
    }
    return 0;
}