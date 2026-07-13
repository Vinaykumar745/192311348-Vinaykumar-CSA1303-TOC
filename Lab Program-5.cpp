#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if string belongs to CFG
bool checkS(char *str, int start, int end);
bool checkA(char *str, int start, int end);

// Check for S ? 0S0 | A
bool checkS(char *str, int start, int end) {
    if (start > end) return true; // e case

    // Case: S ? 0S0
    if (str[start] == '0' && str[end] == '0') {
        return checkS(str, start + 1, end - 1);
    }

    // Case: S ? A
    return checkA(str, start, end);
}

// Check for A ? 1A | e
bool checkA(char *str, int start, int end) {
    if (start > end) return true; // e case

    // All characters must be '1'
    for (int i = start; i <= end; i++) {
        if (str[i] != '1') return false;
    }
    return true;
}

int main() {
    char str[100];
    printf("Enter a string (only 0s and 1s): ");
    scanf("%s", str);

    int len = strlen(str);

    if (checkS(str, 0, len - 1)) {
        printf("String ACCEPTED by CFG.\n");
    } else {
        printf("String REJECTED by CFG.\n");
    }

    return 0;
}

