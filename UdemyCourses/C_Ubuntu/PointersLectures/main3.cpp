#include <iostream>

using namespace std;

struct abc{
    int b;
    int a;
};

void func(struct abc* ptr){
    ptr -> a = 50;
}

int main(){
    
    struct abc* a = new struct abc;
    a-> b = 32;
    a-> a = 22;
    func(a);

    cout << a->a << endl;
    delete a;

    return 0;
}