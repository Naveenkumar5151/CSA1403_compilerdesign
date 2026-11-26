#include <stdio.h>
#include <string.h>

#define MAX 100
typedef struct {
    char name[50], type[30], scope[30];
    int address;
} Symbol;

int main(void) {
    Symbol table[MAX];
    int count = 0, choice, i, found;
    char name[50];
    do {
        printf("\n--- SYMBOL TABLE ---\n1. Insert\n2. Search\n3. Display\n4. Delete\n0. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) {
            if (count == MAX) { puts("Table is full."); continue; }
            printf("Name: "); scanf("%49s", table[count].name);
            printf("Type: "); scanf("%29s", table[count].type);
            printf("Scope: "); scanf("%29s", table[count].scope);
            printf("Address (integer): "); scanf("%d", &table[count].address);
            count++;
            puts("Symbol inserted.");
        } else if (choice == 2) {
            printf("Name to search: "); scanf("%49s", name);
            found = 0;
            for (i = 0; i < count; i++)
                if (strcmp(table[i].name, name) == 0) {
                    printf("Found: %s %s %s %d\n", table[i].name, table[i].type,
                           table[i].scope, table[i].address);
                    found = 1; break;
                }
            if (!found) puts("Symbol not found.");
        } else if (choice == 3) {
            puts("\nNAME\tTYPE\tSCOPE\tADDRESS");
            for (i = 0; i < count; i++)
                printf("%s\t%s\t%s\t%d\n", table[i].name, table[i].type,
                       table[i].scope, table[i].address);
            if (!count) puts("(empty)");
        } else if (choice == 4) {
            printf("Name to delete: "); scanf("%49s", name);
            found = 0;
            for (i = 0; i < count; i++) if (strcmp(table[i].name, name) == 0) {
                int j;
                for (j = i; j < count - 1; j++) table[j] = table[j+1];
                count--; found = 1; puts("Symbol deleted."); break;
            }
            if (!found) puts("Symbol not found.");
        }
    } while (choice != 0);
    return 0;
}
