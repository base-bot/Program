#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    // strings[3] = "dog";

    
// First Way to Do it
    for (int i = 0; i<strings.size(); i++){
        cout << strings[i] << endl;
    }

// Second Way to Do it
    // vector <string> ::iterator it = strings.begin();
    // it++;

    // cout << *it << endl;

// Third Way to Do it
    for (vector <string> ::iterator it = strings.begin(); it!=strings.end(); it++){
        cout << *it << endl;

    }

    return 0;
}