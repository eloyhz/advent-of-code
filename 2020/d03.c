#include <stdio.h>
#include <string.h>

#define MAXROW 400
#define MAXCOL 40

char grid[MAXROW][MAXCOL];
int count = 0;

long long calculate(int right, int down);

int main(void)  {
    freopen("d03.in", "r", stdin);
    while (scanf("%s", grid[count++]) != EOF) {
        // keep reading
    }
    long long ans = calculate(1, 1);
    ans *= calculate(3, 1);
    ans *= calculate(5, 1);
    ans *= calculate(7, 1);
    ans *= calculate(1, 2);
    printf("%lld\n", ans);
    return 0;
}

long long calculate(int right, int down) {
    long long ans = 0;
    int n = strlen(grid[0]);
    for (int i = 0, j = 0; i < count; i += down) {
        if (grid[i][j] == '#')
            ans++;
        j = (j + right) % n;
    }
    return ans;
}