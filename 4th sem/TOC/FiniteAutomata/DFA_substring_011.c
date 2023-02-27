#include <stdio.h>
#include <string.h>

// The transition function for the DFA.
int transition(int state, char c) {
    switch(state) {
        case 0:
            if (c == '0') {
                return 1;
            } else if (c == '1') {
                return 0;
            }
            break;
        case 1:
            if (c == '0') {
                return 1;
            } else if (c == '1') {
                return 2;
            }
            break;
        case 2:
            if (c == '0') {
                return 1;
            } else if (c == '1') {
                return 3;
            }
            break;
        case 3:
            if (c == '0') {
                return 3;
            } else if (c == '1') {
                return 3;
            }
            break;
    }
    return -1; // Invalid state.
}

// The main function.
int main() {
    int state = 0; // The initial state is q0.
    char input[100];
    printf("Enter an input string: ");
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        state = transition(state, input[i]); // Transition to the next state.
        if (state == -1) {
            printf("Invalid input.\n");
            return 0;
        }
    }
    if (state == 3) {
        printf("The input string is accepted by the DFA.\n");
    } else {
        printf("The input string is not accepted by the DFA.\n");
    }
    return 0;
}
