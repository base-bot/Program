#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(55);
    vec.push_back(25);
    vec.push_back(33);
    vec.push_back(18);
    vec.push_back(90);
    vec.push_back(100);

    for (int i = 0; i<vec.size(); i++){
        cout << vec.at(i) << endl;
    }
}