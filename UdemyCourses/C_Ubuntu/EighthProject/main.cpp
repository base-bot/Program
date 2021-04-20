#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ofstream file("test.txt");
    if (file.is_open()){
        cout << "File is Open" << endl;
    }

    else{
        cout << "Problem opening file" << endl;
        return 1;
    }

    file << "Hello World" << endl;
    return 0;
}

//Write File using C++