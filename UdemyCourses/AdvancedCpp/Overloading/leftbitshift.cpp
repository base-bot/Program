#include <iostream>

using namespace std;

class Test{
    private:
    int id;
    string name;
    
    public:
    Test(): id(0), name(""){

    }

    Test(int id, string name): id(id), name(name){

    }
    void print(){
        cout << id << ": " << name << endl;
    }

    const Test &operator=(const Test &other){
        
        cout << "assignment running!" << endl;
        id = other.id,
        name = other.name;

        return *this;
    }

    Test(const Test &other){
        cout << "Copy Constructor running!" << endl;
        // id = other.id,
        // name = other.name;
        //OR
        *this = other;
    }

// In this function here we are overriding the cout call function into whatever we want to print out
    friend ostream &operator<<(ostream &out, const Test &test){
        out << test.id << ": " << test.name;
        return out;
    }
};

int main(){
    Test test1(10, "Mike");
    Test test2(20, "Bob");
    
    test1.print();

    cout << test1 << test2 << endl;

    int value = 1+2+5;

    return 0;
}