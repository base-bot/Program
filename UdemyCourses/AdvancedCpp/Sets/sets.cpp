#include <iostream>
#include <set>

using namespace std;


void fusion(string colour1, string colour2){
    string fusioncolour;

    while (fusioncolour != "end"){
        cout << "The fusion of both colours " << colour1 << " and " << colour2 << " is:   " << flush;
        cin >> fusioncolour;
        cout << endl;
    }
}

class Colour{
    private:
    int number;
    string colour;

    public:
    Colour(): colour(""), number(0){

    }
    Colour(const Colour &other){
        cout << "Copy Constructor running!" << endl;
        colour = other.colour;
        number = other.number;
    }
    Colour(string colour, int number): colour(colour), number(number){

    }
    void print() const{
        cout << colour << " , " << number << flush;
    }
    bool operator<(const Colour &other) const{
        return colour < other.colour;
    } 
};

int main(){

    set<Colour> Clr;

    Colour Clr1("blue", 1);
    Colour Clr2("yellow", 2);
    Colour Clr3("red", 3);
    Clr.insert(Clr1);
    Clr.insert(Clr2);
    Clr.insert(Clr3);
    
    cout << "Primary Colours are: " << endl; 

    for(set<Colour>::iterator it=Clr.begin(); it!=Clr.end();it ++){
        it -> print();
        cout << endl;
    }

    fusion("blue", "yellow");
    
    return 0;
}