#include <iostream>
using namespace std;

template<class T>
void print(T n){
    cout << "Template Version " << n << endl;
}

template<class T>
void show(){
    cout << "Show Template Version " << T() << endl;
}

void print(int value){
    cout << "Non-template Version " << value << endl;
}

int main(){

    print<string>("Hello");
    print<int>(3);

    print("Hi There!");

    print(6);
    print<>(6);

    show<string>();
    // show<>();      //does not work

    return 0;
}