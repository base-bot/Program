#include <iostream>
using namespace std;

class myException: public exception{
    public:
    virtual const char* what() const throw(){
        return "Something Bad Happened!";
    }

};

class Test{
    public:
    void goesWrong(){
        throw myException();
    }
};

int main(){
    Test test;

    try {
        test.goesWrong();
    }
    catch(myException &e){
        cout << e.what() << endl;
    }

    return 0;
}