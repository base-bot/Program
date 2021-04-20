#include <iostream>
#include <list>

using namespace std;

int main(){

    list <int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(10);

    list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100); //insert is as push_front or choose which location to insert the new element

    cout << "Element:   " << *it << endl;
    
    list<int>::iterator eraseit = numbers.begin();
    eraseit++;

    numbers.erase(eraseit); 
    cout << "Element:   " << *eraseit << endl;

    for (list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
        cout << *it <<endl;
    }
    
// Case 1
    for (list<int>::iterator it = numbers.begin(); it!=numbers.end();){
        if (*it==2){
            numbers.insert(it, 1234);
        }

        if(*it==1){
            it = numbers.erase(it);
        }
        else{
            it++;
        }
    }

// Case 2
    // for (list<int>::iterator it = numbers.begin(); it!=numbers.end();it++){
    //     if (*it==2){
    //         numbers.insert(it, 1234);
    //     }

    //     if(*it==1){
    //         it = numbers.erase(it);
    //     }
    //     // else{
    //     //     it++;
    //     // }
    // }

// Case 3
    // for (list<int>::iterator it = numbers.begin(); it!=numbers.end();it++){
    //     if (*it==2){
    //         numbers.insert(it, 1234);
    //     }

    //     if(*it==1){
    //         it = numbers.erase(it);
    //     }
    //     else{
    //         it++;
    //     }
    // }

    for (list<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){
        cout << *it <<endl;
    }

    return 0;
}