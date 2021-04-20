#include <iostream>
using namespace std;

template<class T> //to create a template class, common to use single letter in defining template classes
class Test{
    private:
    T obj;

    public:
    Test(T obj){
        this->obj = obj;
    }
    void print(){
        cout << obj << endl;
    }

};

int main(){

    //here string becomes equals to T in the template definition
    Test<string> test1("Hello");
    test1.print();

    return 0;
}