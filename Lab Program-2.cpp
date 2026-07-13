#include <stdio.h>
#include <string.h>

// DFA states
typedef enum { START, SEEN_0, DEAD } State;

State transition(State current, char input) {
    switch (current) {
        case START:
            if (input == '0') return SEEN_0;
            else return DEAD;

        case SEEN_0:
            // Once we’ve seen the starting 0, allow any characters
            return SEEN_0;

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

    // Accept if string started with '0' and ended with '1'
    if (str[0] == '0' && str[len - 1] == '1' && current != DEAD) {
        printf("String ACCEPTED by DFA (starts with 0 and ends with 1).\n");
    } else {
        printf("String REJECTED by DFA.\n");
    }

    return 0;
}

