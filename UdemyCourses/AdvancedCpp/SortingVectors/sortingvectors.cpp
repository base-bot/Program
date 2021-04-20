#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test{
    private:
    int id;
    string name;

    public:
    Test(int id, string name): id(id), name(name){

    }

    ~Test(){
// // When creating a stack, somehow the constructor is deleted and then a copy of the object is newly created. uncomment this line and notice what happens
        cout << "object destroyed!" << endl;
    }

    void print(){
        cout << id << ": " << name << endl;
    }

    bool operator<(const Test &other) const{
        return name<other.name;
    }
    friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b){
    return a.id < b.id;
}

int main(){

    vector<Test> tests; 

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "John"));
    tests.push_back(Test(7, "Sue"));
    tests.push_back(Test(3, "Vickie"));

    sort(tests.begin(),tests.end(), comp);

    for(int i=0; i<tests.size();i++){
        tests[i].print();
    }

    return 0;
}