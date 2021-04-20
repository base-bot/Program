#include <iostream>

using namespace std;

class Animal{
    public: 
    Animal() {

    }

    virtual ~Animal(){

    }
};

class Dog : public Animal{
    public:
    Dog() : Animal(){

    }

    virtual ~Dog(){

    }

    int abc;
};

int main(){
    Animal* animal = new Dog();
    Dog* dog = (Dog*) animal; 
    dog ->abc = 32;   
    cout << dog->abc<< endl;
    return 0;
}