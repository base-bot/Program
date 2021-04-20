#include <iostream>

using namespace std;

enum LedState{
    LED_STATE_RED,
    LED_STATE_BLUE,
    LED_STATE_YELLOW
};

void setLedState(LedState state){
    if (state == LED_STATE_RED){
        cout << "LED RED ACTIVATED" << endl;
    }
    else if (state == LED_STATE_BLUE){
        cout << "LED BLUE ACTIVATED" << endl;
    }
    else if (state == LED_STATE_YELLOW){
        cout << "LED YELLOW ACTIVATED" << endl;
    }
    else{
        cout << "Invalid State" << endl;
    }
}

int main(){
    setLedState(LED_STATE_YELLOW);

    return 0;
}