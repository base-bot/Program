#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string outputFileName = "text.txt";

    // ofstream outFile;
    // outFile.open(outputFileName);

    //OR
    fstream outFile;
    outFile.open(outputFileName, ios::out);

    if(outFile.is_open()){
        outFile << "Hello There" <<endl;
        outFile << "Fuck You" << endl;
        outFile << 22 << "Times" << endl;
        outFile.close();
    }
    else{
        cout << "Could Not Create File!" << outputFileName <<endl;
    }

    return 0;
}