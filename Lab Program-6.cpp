#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Recursive function to check if string belongs to CFG
bool checkS(char *str, int start, int end) {
    // e case: empty substring
    if (start > end) return true;

    // Case: S ? 0S1
    if (str[start] == '0' && str[end] == '1') {
        return checkS(str, start + 1, end - 1);
    }

    // Otherwise, not valid
    return false;
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

