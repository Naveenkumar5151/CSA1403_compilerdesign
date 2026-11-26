#include <stdio.h>

int main(void) {
    puts("Grammar:");
    puts("E -> E + T | T");
    puts("T -> T * F | F");
    puts("F -> ( E ) | id");
    puts("\nLEADING (FIRSTVT) sets:");
    puts("LEADING(E) = { +, (, id }");
    puts("LEADING(T) = { *, (, id }");
    puts("LEADING(F) = { (, id }");
    return 0;
}
