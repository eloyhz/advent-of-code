#include <stdio.h>
#include <string.h>

int main(void)  {
    const char *fields[] = {"byr", "iyr", "eyr", "hgt",
                         "hcl", "ecl", "pid", "cid"};

    char c, key[4];
    while ((c = getchar()) != EOF)  {
        putchar(c);
    }
    return 0;
}