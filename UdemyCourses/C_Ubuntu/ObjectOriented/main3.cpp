#include <iostream>
#include "dog.h"
#include "cat.h"

using namespace std;

int main(){
    Dog* dog = new Dog(32);
    dog->myFunction();
    dog->myFunction(22);

    dog->action();

    Dog* dog2 = new Dog(42);

    Cat* cat = new Cat(70);
    cat->action();
    Animal* animal = dog;
    animal->action();

// In this case below, animal does not own a myFunction() function, hence an error will be thrown.
// However since this function has been overriden my Dog or Cat class, 
// depending on what animal refers to as a pointer, the overriden function in the corresponding class (Dog or Cat) will be used.
   
    // animal->myFunction)();
    
    cout << "Dogs Speed:  " << dog->getSpeed() << endl;

    std::cout << "Dog1 Total legs: " << dog->getTotalLegs() << std::endl;
    std::cout << "Dog2 Total legs: " << dog2->getTotalLegs() << std::endl;

    delete dog; delete dog2;
    return 0;
}