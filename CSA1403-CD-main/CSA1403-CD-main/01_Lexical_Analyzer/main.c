#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char s[4096];
    int i = 0;
    printf("Enter a C-like source line (or a few lines):\n");
    if (!fgets(s, sizeof(s), stdin)) return 0;

    while (s[i]) {
        if (isspace((unsigned char)s[i])) { i++; continue; }

        if (s[i] == '/' && s[i+1] == '/') break;
        if (s[i] == '/' && s[i+1] == '*') {
            i += 2;
            while (s[i] && !(s[i] == '*' && s[i+1] == '/')) i++;
            if (s[i]) i += 2;
            continue;
        }

        if (isalpha((unsigned char)s[i]) || s[i] == '_') {
            char token[256]; int j = 0;
            while ((isalnum((unsigned char)s[i]) || s[i] == '_') && j < 255)
                token[j++] = s[i++];
            token[j] = '\0';
            printf("IDENTIFIER : %s\n", token);
        } else if (isdigit((unsigned char)s[i])) {
            char token[256]; int j = 0;
            while ((isalnum((unsigned char)s[i]) || s[i] == '.') && j < 255)
                token[j++] = s[i++];
            token[j] = '\0';
            printf("CONSTANT   : %s\n", token);
        } else if (strchr("+-*/%=<>!&|^", s[i])) {
            char op[3] = {s[i], '\0', '\0'};
            if ((s[i+1] == '=' && strchr("+-*/%=<>!", s[i])) ||
                (s[i] == '+' && s[i+1] == '+') ||
                (s[i] == '-' && s[i+1] == '-') ||
                (s[i] == '&' && s[i+1] == '&') ||
                (s[i] == '|' && s[i+1] == '|')) {
                op[1] = s[i+1]; i += 2;
            } else i++;
            printf("OPERATOR   : %s\n", op);
        } else {
            printf("SPECIAL    : %c\n", s[i++]);
        }
    }
    return 0;
}
