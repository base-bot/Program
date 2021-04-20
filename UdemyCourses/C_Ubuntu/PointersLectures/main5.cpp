#include <iostream>

using namespace std;

void test(int& var){
    cout << "Var value = " << var << endl;
}

int abc = 50;

int& do_something()
{
    return abc;
}
int main(){
    do_something() = 22;
    cout << "abc = " << abc << endl;
    return 0;
}