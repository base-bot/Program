#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    protected:
    int speed;

    public:
    Animal(int speed);
    virtual ~Animal();
    virtual int getSpeed();

//prevents this class to be created on it own: no animal can be created on its own; it should belong to a class that is a kid to it
    virtual void action()=0; 
};
#endif