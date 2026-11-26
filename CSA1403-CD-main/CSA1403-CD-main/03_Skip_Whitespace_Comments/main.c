#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char s[4096];
    int i = 0;
    printf("Enter source text:\n");
    if (!fgets(s, sizeof(s), stdin)) return 0;
    printf("Text after removing whitespace and comments:\n");
    while (s[i]) {
        if (isspace((unsigned char)s[i])) { i++; continue; }
        if (s[i] == '/' && s[i+1] == '/') break;
        if (s[i] == '/' && s[i+1] == '*') {
            i += 2;
            while (s[i] && !(s[i] == '*' && s[i+1] == '/')) i++;
            if (s[i]) i += 2;
            continue;
        }
        putchar(s[i++]);
    }
    putchar('\n');
    return 0;
}
