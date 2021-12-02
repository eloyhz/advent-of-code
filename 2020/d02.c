#include <stdio.h>

void part1(void);
void part2(void);

int main(void)  {
    freopen("d02.in", "r", stdin);
    // part1();
    part2();
    return 0;
}

void part1(void)  {
    int lowest, highest;
    char letter;
    char password[30];
    int valid = 0;
    while (scanf("%d-%d %c: %s", &lowest, &highest, &letter, password) != EOF)  {
        int count = 0;
        for (const char *c = password; *c != '\0'; c++)
            if (*c == letter)
                count++;
        if (count >= lowest && count <= highest)
            valid++;
    }
    printf("%d\n", valid);
}

void part2(void)  {
    int pos1, pos2;
    char letter;
    char password[30];
    int valid = 0;
    while (scanf("%d-%d %c: %s", &pos1, &pos2, &letter, password) != EOF)  {
        if (letter == password[pos1-1] && letter == password[pos2-1])
            continue;
        if (letter == password[pos1-1] || letter == password[pos2-1])
            valid++;
    }
    printf("%d\n", valid);
}