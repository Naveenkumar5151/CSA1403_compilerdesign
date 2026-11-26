#include <stdio.h>

int main(void) {
    char s[2048];
    int i, found = 0;
    printf("Enter an expression:\n");
    if (!fgets(s, sizeof(s), stdin)) return 0;
    for (i = 0; s[i]; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            printf("%c : arithmetic operator\n", s[i]);
            found = 1;
        }
    }
    if (!found) puts("No arithmetic operators found.");
    return 0;
}
