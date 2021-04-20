#include <iostream>

using namespace std;


void mightGoWrong(){
// In Exceptions, one hsould know that as soon as the exception is thrown, the function is exited. 
// That is why we only get as an output the first exception only

    bool error1 = false;
    bool error2 = true;
    bool error3 = true;

    if (error1){
        throw 8;
    }
    if (error2){
        throw "Something Went Wrong";
    }
    if (error3){
        throw string("Something Else Went Wrong");
    }
}

void useMightGoWrong(){
    mightGoWrong();
}

int main(){
    try{
        useMightGoWrong();
    }
    catch (int e){
        cout << "Error Code:  " << e << endl;
    }
    catch (char const* e){
        cout << "Error Message:  " << e << endl;
    }
    catch(string &e){
        cout << "String Error Message:  " << e << endl;
    }
    

    cout << "still Running!" << endl;

    return 0;
}