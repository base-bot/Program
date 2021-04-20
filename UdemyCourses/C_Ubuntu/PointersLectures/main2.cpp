#include <iostream>

using namespace std;

struct abc{
    int b;
    int a;
};

int main(){
    struct abc a;
    a.a = 50;
    a.b = 25;

    struct abc* ptr = &a;
    ptr ->b = 80;
    ptr ->a = 91;

    cout << "a.a = " << a.a << endl;
    return 0;
}