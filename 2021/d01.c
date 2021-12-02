#include <stdio.h>

int main(void)  {
    int prev, current;
    int count = 0;

    scanf("%d", &prev);
    while (scanf("%d", &current) == 1)  {
        if (current > prev)
            count++;
        prev = current;
    }
    printf("%d\n", count);
}