#include "animal.h"
#include <iostream>
using namespace std;

Animal::Animal(int speed){
    cout << "ANIMAL CONSTRUCTED" << endl;
    this->speed = speed;    
}

Animal::~Animal(){
    cout << "ANIMAL DESTRUCTED" << endl;    
}

int Animal::getSpeed(){
    return this->speed;
}