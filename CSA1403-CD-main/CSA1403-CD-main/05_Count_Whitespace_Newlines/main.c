#include <stdio.h>

int main(void) {
    int c, spaces = 0, tabs = 0, newlines = 0, other_ws = 0;
    puts("Enter text (Ctrl+Z then Enter on Windows, Ctrl+D on Linux/macOS to finish):");
    while ((c = getchar()) != EOF) {
        if (c == ' ') spaces++;
        else if (c == '\t') tabs++;
        else if (c == '\n') newlines++;
        else if (c == '\r' || c == '\v' || c == '\f') other_ws++;
    }
    printf("Spaces: %d\nTabs: %d\nNewline characters: %d\nOther whitespace: %d\n",
           spaces, tabs, newlines, other_ws);
    return 0;
}
