#include <iostream>
#include <map>

using namespace std;

class Person{

    private:
    string name;
    int age;

    public:
    Person(): name(""), age(0){

    }
    Person(const Person &other){
        cout << "Copy Constructor running!" << endl;
        name = other.name;
        age = other.age;
        cout << "Name:   " << name << endl;
    }
    Person(string name, int age): name(name), age(age){

    }
    void print(){
        cout << name << ": " << age << endl;
    }
};

int main(){

    map <int, Person> people;

    people[50] = Person("Mike", 40);
    people[32] = Person("Vickie",20);
    people[1] = Person("Roj",30);

    // people.insert(make_pair(55,Person("Bob", 45)));
    people.insert(make_pair(55,Person("Julia", 65)));

    for(map<int, Person>::iterator it=people.begin(); it!=people.end(); it++){
        cout << it->first << " : " << flush;
        it->second.print();

    }
    return 0;
}