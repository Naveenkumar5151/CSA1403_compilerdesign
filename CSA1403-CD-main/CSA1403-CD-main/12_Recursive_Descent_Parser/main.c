#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[512];
int pos = 0, error = 0;

void E(void); void T(void); void F(void);
void Eprime(void); void Tprime(void);

void match(char c) {
    if (input[pos] == c) pos++;
    else error = 1;
}
void F(void) {
    if (strncmp(input + pos, "id", 2) == 0) pos += 2;
    else if (input[pos] == '(') { match('('); E(); match(')'); }
    else error = 1;
}
void Tprime(void) {
    while (!error && input[pos] == '*') { match('*'); F(); }
}
void T(void) { F(); Tprime(); }
void Eprime(void) {
    while (!error && input[pos] == '+') { match('+'); T(); }
}
void E(void) { T(); Eprime(); }

int main(void) {
    printf("Enter expression using id, +, *, and parentheses (example: id+id*id): ");
    if (scanf("%511s", input) != 1) return 0;
    E();
    if (!error && input[pos] == '\0') puts("String accepted.");
    else puts("String rejected.");
    return 0;
}
