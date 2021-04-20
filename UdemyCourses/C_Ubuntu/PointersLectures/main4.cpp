#include <iostream>

using namespace std;

struct abc{
    int b;
    int a;
};

int main(){
    
    int* array = new int[10];
    for (int i=0; i< 10 ; i++){
        array[i] = i;
    }

    for (int i =0; i<10; i++){
        cout << array[i] << endl;
    }

    delete[] array;
    return 0;
}