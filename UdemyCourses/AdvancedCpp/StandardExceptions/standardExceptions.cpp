#include <iostream>
using namespace std;

class CanGoWrong{
    public:
    CanGoWrong(){
        char *pMemory = new char[999999999999]; //throws exceptions due to the fact that the code cannot allocate that much memory
        delete[] pMemory;
    }
};


int main(){
    try {

        CanGoWrong wrong;
    }
    catch(bad_alloc &e){
        cout << "Caught Exception " <<  e.what() << endl;
    }

    cout << "StillRunning" << endl;

    return 0;
}