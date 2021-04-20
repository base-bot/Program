#include <iostream>
using namespace std;

void goesWrong(){
    bool error1Detected = false;
    bool error2Detected = true;

    if (error1Detected){
        throw bad_alloc();
    }
    if (error2Detected){
        throw exception();
    }
}

int main(){

    try{
        goesWrong();

    }
    catch (exception &e) {
        cout<< "Catch Exception" << e.what()<<endl;
    }
    catch (bad_alloc &e) {
        cout<< "Catch bad_alloc" << e.what()<<endl;
    }

    return 0;
}