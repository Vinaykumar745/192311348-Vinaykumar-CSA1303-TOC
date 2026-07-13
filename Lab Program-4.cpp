#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if string is palindrome over {0,1}
bool belongsToCFG(char *str) {
    int len = strlen(str);

    // e (empty string) is valid
    if (len == 0) return true;

    // Check all characters are 0 or 1
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1') {
            return false; // invalid symbol
        }
    }

    // Check palindrome property
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char str[100];
    printf("Enter a string (only 0s and 1s): ");
    scanf("%s", str);

    if (belongsToCFG(str)) {
        printf("String ACCEPTED by CFG (palindrome over {0,1}).\n");
    } else {
        printf("String REJECTED by CFG.\n");
    }

    return 0;
}

