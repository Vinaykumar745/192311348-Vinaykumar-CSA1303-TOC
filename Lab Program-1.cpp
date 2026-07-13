#include <stdio.h>
#include <string.h>

// DFA states
typedef enum { START, SEEN_A, ACCEPT, DEAD } State;

State transition(State current, char input) {
    switch (current) {
        case START:
            if (input == 'a') return SEEN_A;
            else return DEAD;

        case SEEN_A:
            if (input == 'a') return SEEN_A;   // stay in SEEN_A
            else return SEEN_A;                // allow other chars, but track last

        case DEAD:
            return DEAD;

        default:
            return DEAD;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    State current = START;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        current = transition(current, str[i]);
    }

    // Accept if string started with 'a' and ended with 'a'
    if (str[0] == 'a' && str[len - 1] == 'a' && current != DEAD) {
        printf("String ACCEPTED by DFA (starts and ends with 'a').\n");
    } else {
        printf("String REJECTED by DFA.\n");
    }

    return 0;
}

