#include "dog.h"
#include <iostream>

using namespace std;

Dog::Dog(int TotalLegs) : Animal(20){
    this->TotalLegs = TotalLegs;
    this->speed = 30;
}
Dog::~Dog(){
    cout << "Dog Destructed!" << endl;
}

void Dog::setTotalLegs(int total_legs){
    this -> TotalLegs = total_legs;
}

int Dog::getTotalLegs(){
    return this -> TotalLegs;
}

void Dog::myFunction(){
    cout << "My Function with NO Arguments" << endl;
}
void Dog::myFunction(int a){
    cout << "My Function with INTEGER Arguments" << endl;
}

int Dog::getSpeed(){
    // return 90;
    // return Animal::getSpeed() + 20;
    int speed = Animal::getSpeed() + 100;
    return speed;
}

void Dog::action(){
    cout << "Dog Action INVOKED" << endl;
}