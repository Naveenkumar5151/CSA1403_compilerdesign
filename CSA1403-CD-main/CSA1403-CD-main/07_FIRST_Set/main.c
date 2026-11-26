#include <stdio.h>

int main(void) {
    puts("Grammar:");
    puts("S -> AaAb | BbBa");
    puts("A -> epsilon");
    puts("B -> epsilon");
    puts("\nFIRST sets:");
    puts("FIRST(A) = { epsilon }");
    puts("FIRST(B) = { epsilon }");
    puts("FIRST(S) = { a, b }");
    return 0;
}
