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
    void print() const{ 
//here a const is needed because when printing our variables, we need to tell the user not to confuse the class data variables
//and when using const, the user now will know the order of the variables ( and in this case, print the name and then the age)
        cout << name << ": " << age << flush;
    }

//we put this message in order to let the compiler compare what it is doing in a different order than the usual order
    bool operator<(const Person &other) const{
        if(name==other.name){
            return age < other.age;     //check difference with and without this "if" command
        }
        return name < other.name;
    }
};

int main(){

    map <Person, int> people;

    people[Person("Mike", 40)] = 40;
    people[Person("Vickie",20)] = 20 ;
    people[Person("Roj",30)] = 30;
    people[Person("Mike",44)] = 70;

    for(map<Person, int>::iterator it=people.begin(); it!=people.end(); it++){
        cout << it->second << " : " << flush;
        it->first.print();
         cout << endl;

    }
    return 0;
}