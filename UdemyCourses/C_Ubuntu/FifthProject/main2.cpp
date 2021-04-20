#include <iostream>

using namespace std;

int main(){

    int count;
    cout << "Enter how Many: " << endl;
    cin >> count;
    int array[count];
    for (int i = 0; i<count;i++){
        cout << "Enter the value: " << endl;
        cin >> array[i];
    }

    for (int i = 0;i<count;i++){
        cout << "Value for index " << i << ": " << array[i]<< endl;
    }
    return 0;
}