#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test{
    private:
    string name;

    public:
    Test(string name): name(name){

    }

    ~Test(){
// // When creating a stack, somehow the constructor is deleted and then a copy of the object is newly created. uncomment this line and notice what happens
        cout << "object destroyed!" << endl;
    }

    void print(){
        cout << name << endl;
    }
};

int main(){

// Stacks (LIFO)
    stack<Test> testStack; //last in first out structure

    testStack.push(Test("Mike"));
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    cout << endl;

    // Test &test1 = testStack.top();
    // testStack.pop();
    // test1.print();                  //These three lines of code are considered to be badly written and it is by coincidence that this one is working
                                    //because as soon as we pop one object, the object is automatically destroyed. So the reference refers to a destroyed object

    while(testStack.size()>0){
        Test &test = testStack.top();   //top() here for stacks
        test.print();
        testStack.pop();
    }    

    // testStack.pop();
    // Test test2 = testStack.top();
    // test2.print();


// Queues (FIFO)

    queue<Test> testQueue; //last in first out structure

    testQueue.push(Test("Mike"));
    testQueue.push(Test("John"));
    testQueue.push(Test("Sue"));

    cout << endl;

    // Test &test1 = testQueue.top();
    // testQueue.pop();
    // test1.print();                  //These three lines of code are considered to be badly written and it is by coincidence that this one is working
                                    //because as soon as we pop one object, the object is automatically destroyed. So the reference refers to a destroyed object

    testQueue.back().print();
    cout<<endl;
    while(testQueue.size()>0){
        Test &test = testQueue.front(); //front() here for queues
        test.print();
        testQueue.pop();
    }    

    // testQueue.pop();
    // Test test2 = testQueue.top();
    // test2.print();


    return 0;
}