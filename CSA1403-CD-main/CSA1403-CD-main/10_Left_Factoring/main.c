#include <stdio.h>

int main(void) {
    puts("Original grammar:");
    puts("S -> iEtS | iEtSeS | a");
    puts("E -> b");
    puts("\nAfter left factoring:");
    puts("S  -> iEtS S' | a");
    puts("S' -> eS | epsilon");
    puts("E  -> b");
    return 0;
}
