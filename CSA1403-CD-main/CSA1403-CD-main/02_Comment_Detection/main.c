#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char line[2048];
    int start = 0, end;
    printf("Enter one line:\n");
    if (!fgets(line, sizeof(line), stdin)) return 0;

    while (isspace((unsigned char)line[start])) start++;
    end = (int)strlen(line) - 1;
    while (end >= start && isspace((unsigned char)line[end])) end--;

    if (line[start] == '/' && line[start+1] == '/') {
        printf("It is a single-line comment.\n");
    } else if (line[start] == '/' && line[start+1] == '*' &&
               end - start >= 3 && line[end-1] == '*' && line[end] == '/') {
        printf("It is a block comment.\n");
    } else {
        printf("It is not a complete comment line.\n");
    }
    return 0;
}
