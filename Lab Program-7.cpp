#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string belongs to CFG
bool belongsToCFG(char *str) {
    int len = strlen(str);

    // Must contain "101" in the middle
    for (int i = 0; i <= len - 3; i++) {
        if (str[i] == '1' && str[i+1] == '0' && str[i+2] == '1') {
            // "101" found, check that all other chars are 0 or 1
            for (int j = 0; j < len; j++) {
                if (str[j] != '0' && str[j] != '1') {
                    return false; // invalid symbol
                }
            }
            return true;
        }
    }

    return false; // no "101" found
}

int main() {
    char str[100];
    printf("Enter a string (only 0s and 1s): ");
    scanf("%s", str);

    if (belongsToCFG(str)) {
        printf("String ACCEPTED by CFG.\n");
    } else {
        printf("String REJECTED by CFG.\n");
    }

    return 0;
}

