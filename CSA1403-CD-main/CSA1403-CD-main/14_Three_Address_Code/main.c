#include <stdio.h>
#include <ctype.h>
#include <string.h>

char expr[512], postfix[512], stack[512];
int top = -1, out = 0, temp = 1;

int prec(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
int main(void) {
    int i;
    printf("Enter arithmetic expression (single-character operands): ");
    if (!fgets(expr, sizeof(expr), stdin)) return 0;

    for (i = 0; expr[i]; i++) {
        char c = expr[i];
        if (isspace((unsigned char)c)) continue;
        if (isalnum((unsigned char)c)) postfix[out++] = c;
        else if (c == '(') stack[++top] = c;
        else if (c == ')') {
            while (top >= 0 && stack[top] != '(') postfix[out++] = stack[top--];
            if (top < 0) { puts("Invalid parentheses."); return 1; }
            top--;
        } else if (strchr("+-*/", c)) {
            while (top >= 0 && stack[top] != '(' && prec(stack[top]) >= prec(c))
                postfix[out++] = stack[top--];
            stack[++top] = c;
        } else { printf("Unsupported character: %c\n", c); return 1; }
    }
    while (top >= 0) {
        if (stack[top] == '(') { puts("Invalid parentheses."); return 1; }
        postfix[out++] = stack[top--];
    }
    postfix[out] = '\0';

    char values[512][32]; int vtop = -1;
    for (i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalnum((unsigned char)c)) {
            values[++vtop][0] = c; values[vtop][1] = '\0';
        } else {
            char right[32], left[32], t[32];
            if (vtop < 1) { puts("Invalid expression."); return 1; }
            strcpy(right, values[vtop--]);
            strcpy(left, values[vtop--]);
            sprintf(t, "t%d", temp++);
            printf("%s = %s %c %s\n", t, left, c, right);
            strcpy(values[++vtop], t);
        }
    }
    if (vtop != 0) puts("Invalid expression.");
    else printf("Result is stored in: %s\n", values[vtop]);
    return 0;
}
