#include <iostream>
using namespace std;

int main(int argc, char** argv){
    int age = 22;
    cout << "Enter your age: " << endl;
    cin >> age;

    if (age > 17){
        cout << "You're legal to buy Whiskey!" << endl;
    }
    else{
        cout << "You are too Young to buy Whiskey!" << endl;
    }
}