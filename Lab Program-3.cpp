#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string belongs to the CFG language
bool belongsToCFG(char *str) {
    int len = strlen(str);

    // Must be at least length 2 (for starting 0 and ending 1)
    if (len < 2) return false;

    // Check first and last characters
    if (str[0] != '0' || str[len - 1] != '1') return false;

    // Middle part can be any combination of 0s and 1s (A ? 0A | 1A | e)
    for (int i = 1; i < len - 1; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false; // invalid symbol
        }
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (belongsToCFG(str)) {
        printf("String ACCEPTED by CFG (starts with 0, ends with 1).\n");
    } else {
        printf("String REJECTED by CFG.\n");
    }

    return 0;
}

