#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string inputFileName = "text.txt";

    // ifstream outFile;
    // inFile.open(inputFileName);

    //OR
    fstream inFile;
    inFile.open(inputFileName, ios::in);

    if(inFile.is_open()){
        string line;

        while(!inFile.eof()){
        // OR
        // while(inFile){

        getline(inFile, line);
        // inFile >> line;

        cout << line << endl;
            
        }
        inFile.close();
    }
    else{
        cout << "Could Not Read File!" << inputFileName <<endl;
    }

    return 0;
}