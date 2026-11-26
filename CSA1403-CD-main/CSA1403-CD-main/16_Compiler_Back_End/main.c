#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Educational back end: translates simple three-address statements to pseudo-assembly. */
int main(void) {
    int n, i;
    char line[256], lhs[40], a[40], b[40], op;
    puts("Enter number of three-address statements:");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 0;
    getchar();
    puts("Enter statements such as: t1 = a + b   or   x = t1");
    puts("\nGenerated pseudo-assembly:");
    for (i = 0; i < n; i++) {
        if (!fgets(line, sizeof(line), stdin)) break;
        if (sscanf(line, " %39s = %39s %c %39s", lhs, a, &op, b) == 4) {
            printf("LOAD R0, %s\n", a);
            if (op == '+') printf("ADD R0, %s\n", b);
            else if (op == '-') printf("SUB R0, %s\n", b);
            else if (op == '*') printf("MUL R0, %s\n", b);
            else if (op == '/') printf("DIV R0, %s\n", b);
            else { puts("; Unsupported operator"); continue; }
            printf("STORE %s, R0\n", lhs);
        } else if (sscanf(line, " %39s = %39s", lhs, a) == 2) {
            printf("LOAD R0, %s\nSTORE %s, R0\n", a, lhs);
        } else {
            printf("; Could not parse: %s", line);
        }
    }
    return 0;
}
