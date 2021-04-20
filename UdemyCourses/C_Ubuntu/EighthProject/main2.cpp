#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    streampos begin, end;
    ifstream file("test.txt", ios::binary);
    if (file.is_open()){
        cout << "File is Open" << endl;
    }

    else{
        cout << "Problem opening file" << endl;
        return 1;
    }

    begin = file.tellg();
    file.seekg(0, ios::end);
    end = file.tellg();
//get file size
    cout << "File Size = " << end-begin << endl;
    string msg;
    while (getline(file, msg)){
        cout << msg << endl;
    }

    return 0;
}

//Read File using C++