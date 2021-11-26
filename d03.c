#include <stdio.h>

#define MAXROW 20
#define MAXCOL 20

int main(void)  {
    char grid[MAXROW][MAXCOL];
    int count = 0;
    while (scanf("%s", grid[count++]) != EOF) {
        // keep reading
    }
    for (int i = 0; i < count; i++) {
        for (const char *c = grid[i]; *c != '\0'; c++)
            printf("(%c) ", *c);
        printf("\n");
    }
    return 0;
}