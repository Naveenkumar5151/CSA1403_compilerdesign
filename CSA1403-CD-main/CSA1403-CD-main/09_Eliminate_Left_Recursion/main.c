#include <stdio.h>

int main(void) {
    puts("Original grammar:");
    puts("S -> (L) | a");
    puts("L -> L , S | S");
    puts("\nAfter eliminating immediate left recursion:");
    puts("S  -> (L) | a");
    puts("L  -> S L'");
    puts("L' -> , S L' | epsilon");
    return 0;
}
