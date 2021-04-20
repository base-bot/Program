#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)


struct Person {
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int main(){

    Person someone = {"Frodo", 220, 80};
    string fileName = "test.bin";
// // Write Binary File
    ofstream outputFile;
    outputFile.open(fileName, ios::binary);

    if(outputFile.is_open()){
        outputFile.write((char *)&someone, sizeof(Person));
        // OR
        // outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));

        outputFile.close();
    }

    else{
        cout << "Could not Create File" + fileName << endl;
    }
    
// // Read Binary File

    Person someoneElse = {};

    ifstream inputFile;
    inputFile.open(fileName, ios::binary);

    if(inputFile.is_open()){
        inputFile.read((char *)&someoneElse, sizeof(Person));
        // OR
        // inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

        inputFile.close();
    }

    else{
        cout << "Could not Read File" + fileName << endl;
    }

    cout << someoneElse.name << " , " << someoneElse.age << " , " <<someoneElse.weight << endl;

    return 0;
}