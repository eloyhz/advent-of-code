#include <stdio.h>

#define MAX 201

int main(void)  {
    int report[MAX];
    int expense;
    int n = 0;
    freopen("d01.in", "r", stdin);
    while (scanf("%d", &expense) != EOF)   {
        report[n++] = expense;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (report[i] + report[j] + report[k] == 2020)  {
                    printf("%d\n", report[i] * report[j] * report[k]);
                }
            }
        }
    }
    return 0;
}