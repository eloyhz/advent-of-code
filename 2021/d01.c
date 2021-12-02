#include <stdio.h>

#define MAX 2000

int main(void)  {
    int prev1, prev2, current;
    int prev_sum, current_sum;
    int count = 0;

    freopen("d01.in", "r", stdin);

    scanf("%d", &prev1);
    scanf("%d", &prev2);
    scanf("%d", &current);
    prev_sum = current + prev2 + prev1;
    prev1 = prev2;
    prev2 = current;
    while (scanf("%d", &current) == 1)  {
        current_sum = current + prev2 + prev1;
        if (current_sum > prev_sum)
            count++;
        prev_sum = current_sum;
        prev1 = prev2;
        prev2 = current;
    }
    printf("%d\n", count);
}