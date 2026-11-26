#include <stdio.h>
#include <string.h>

char s[256];
int p = 0;

int S(void) {
    if (s[p] != 'a') return 0;
    p++;
    if (s[p] == 'b') { p++; return 1; }   /* S -> ab */
    if (s[p] == 'a' && S()) {
        if (s[p] == 'b') { p++; return 1; } /* S -> aSb */
    }
    return 0;
}

int main(void) {
    printf("Grammar: S -> aSb | ab\nEnter input string: ");
    if (scanf("%255s", s) != 1) return 0;
    if (S() && s[p] == '\0') puts("String accepted by the grammar.");
    else puts("String rejected by the grammar.");
    return 0;
}
