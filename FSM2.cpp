#include <iostream>
using namespace std;

#define STATE_OFF (0)
#define STATE_ON  (1)

int runStateOff(const bool isSwitchFlipped) {
    int nextState = STATE_OFF;
    cout << "State is off and the isSwitchFlipped is " << isSwitchFlipped << endl;
    if (isSwitchFlipped) {
        cout << "Transition to the next state ON" << endl;
        nextState = STATE_ON;
    }

    return nextState;
}

int runStateOn(const bool isSwitchFlipped) {
    int nextState = STATE_ON;
    cout << "State is on and the isSwitcchFlipped is " << isSwitchFlipped << endl;
    if (isSwitchFlipped) {
        cout << "Transition to the next state OFF" << endl;
        nextState = STATE_OFF;
    }

    return nextState;
}

int main() {
    int currentState = STATE_OFF;
    int nextState    = STATE_OFF;
    for (int i = 0; i < 10; i++) {
        cout << "Iteration = " << i << endl;
        bool isSwitchFlipped = rand() % 2;
        switch (currentState) {
        case STATE_OFF:
            nextState = runStateOff(isSwitchFlipped);
            break;
        case STATE_ON:
            nextState = runStateOn(isSwitchFlipped);
            break;
        default:
            cout << "Invalid state = " << currentState << endl;
            exit(1);
            break;
        }
        currentState = nextState;
    }
    return 0;
}
