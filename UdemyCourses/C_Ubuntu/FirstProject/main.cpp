#include <iostream>
using namespace std;
int sum(int x, int y){
    return x + y;
}

int main(int argc, char** argv)
{
    int result = sum(5,5);
    cout << "The result of 5 + 5 is ..... " << result << endl;
    return 0;
}