#include "cat.h"
#include <iostream>

using namespace std;

Cat::Cat(int TotalLegs) : Animal(20){
    this->TotalLegs = TotalLegs;
    this->speed = 30;
}
Cat::~Cat(){
    cout << "Dog Destructed!" << endl;
}

void Cat::setTotalLegs(int total_legs){
    this -> TotalLegs = total_legs;
}

int Cat::getTotalLegs(){
    return this -> TotalLegs;
}

void Cat::myFunction(){
    cout << "My Function with NO Arguments" << endl;
}
void Cat::myFunction(int a){
    cout << "My Function with INTEGER Arguments" << endl;
}

int Cat::getSpeed(){
    // return 90;
    // return Animal::getSpeed() + 20;
    int speed = Animal::getSpeed() + 100;
    return speed;
}

void Cat::action(){
    cout << "C A T Action INVOKED" << endl;
}