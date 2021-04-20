#include <iostream>

using namespace std;

int main(){
    int i = 0, times = 0;
    cin >> times;

    do{
        if (i == 5){
            i++;
            continue;
        }
        cout << i << ". MESSAGE" << endl;
        i++;
    }
    while (i < times);
    return 0;
}