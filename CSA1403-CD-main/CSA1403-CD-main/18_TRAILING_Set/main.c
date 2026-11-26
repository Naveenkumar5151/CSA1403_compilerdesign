#include <stdio.h>

int main(void) {
    puts("Grammar:");
    puts("E -> E + T | T");
    puts("T -> T * F | F");
    puts("F -> ( E ) | id");
    puts("\nTRAILING (LASTVT) sets:");
    puts("TRAILING(E) = { +, ), id }");
    puts("TRAILING(T) = { *, ), id }");
    puts("TRAILING(F) = { ), id }");
    return 0;
}
