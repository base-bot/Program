#include <iostream>
#include <map>

using namespace std;

int main(){

    map <string, int> ages;

    ages["Mike"] = 40;
    ages["Roj"] = 20;
    ages["Vickie"] = 30;

    ages["Mike"] = 70;

    // pair<string, int> addToMap("Peter", 100);
    // ages.insert(addToMap);                           //Method 1

    // ages.insert(pair<string, int>("Peter", 100));       //Method 2

    ages.insert(make_pair("Peter",100));                //Method 3

    ages.insert(pair<string, int>("Antoine", 50));


    cout << ages["Roj"] << endl;

    cout << ages["Yo"] << endl;

    // if(ages.find("Larn") != ages.end()){
    if(ages.find("Vickie") != ages.end()){
        cout << "Found Vickie!!" <<endl;
    }
    else{
        cout << "Key Not Found." << endl;
    }
    for(map<string, int>::iterator it=ages.begin(); it!=ages.end(); it++){
// // Method 1
//         cout << it->first << ": " << it->second<<endl;

// Merhod 2
        pair<string, int> age = *it;
        cout << age.first << " : " << age.second << endl;

    }
    return 0;
}