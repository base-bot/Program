#ifndef CAT_H
#define CAT_H
#include "animal.h"

class Cat: public Animal{
    private:
    int TotalLegs;

    public:
    Cat(int TotalLegs);
    virtual ~Cat();

    void setTotalLegs(int total_legs);
    int getTotalLegs();
    void myFunction();
    void myFunction(int a);
    virtual int getSpeed();
    virtual void action();
};

#endif