#ifndef DOG_H
#define DOG_H
#include "animal.h"

class Dog: public Animal{
    private:
    int TotalLegs;

    public:
    Dog(int TotalLegs);
    virtual ~Dog();

    void setTotalLegs(int total_legs);
    int getTotalLegs();
    void myFunction();
    void myFunction(int a);
    virtual int getSpeed();
    virtual void action();
};

#endif