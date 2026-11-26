#include <stdio.h>

int main(void) {
    puts("Grammar:");
    puts("S -> AaAb | BbBa");
    puts("A -> epsilon");
    puts("B -> epsilon");
    puts("\nFOLLOW sets:");
    puts("FOLLOW(S) = { $ }");
    puts("FOLLOW(A) = { a, b }");
    puts("FOLLOW(B) = { a, b }");
    return 0;
}
