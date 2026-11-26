#include <stdio.h>
#include <ctype.h>

int main(void) {
    char filename[256];
    FILE *fp;
    int c, inword = 0, chars = 0, words = 0, lines = 0, last = '\n';
    printf("Enter file name: ");
    if (scanf("%255s", filename) != 1) return 0;
    fp = fopen(filename, "r");
    if (!fp) { perror("Cannot open file"); return 1; }
    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace((unsigned char)c)) inword = 0;
        else if (!inword) { words++; inword = 1; }
        last = c;
    }
    if (chars > 0 && last != '\n') lines++;
    fclose(fp);
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}
