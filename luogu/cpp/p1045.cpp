#include <cstdio>
#include <cmath>
int w[110] = {0}, n, a, t;
int main()
{
    scanf("%d", &n);
    double ans;
    ans = n * (log(2) / log(10));
    a = ceil(ans);
    printf("%d\n", a);
    w[100] = 1;
    for (int i = 1; i <= n / 13; i++)
    {
        t = 0;
        for (int j = 100; j >= 1; j--)
        {
            w[j] = 8192 * w[j] + t;
            t = w[j] / 100000;
            w[j] %= 100000;
        }
    }
    for (int i = 1; i <= n % 13; i++)
    {
        t = 0;
        for (int j = 100; j >= 1; j--)
        {
            w[j] = 2 * w[j] + t;
            t = w[j] / 100000;
            w[j] %= 100000;
        }
    }
    w[100] -= 1;
    for (int i = 1; i <= 100; i++)
    {
        if (w[i] / 10000)
            printf("%d", w[i]);
        else if (w[i] / 1000)
            printf("0%d", w[i]);
        else if (w[i] / 100)
            printf("00%d", w[i]);
        else if (w[i] / 10)
            printf("000%d", w[i]);
        else if (w[i] / 1)
            printf("0000%d", w[i]);
        else
            printf("00000");
        if (i % 10 == 0)
            printf("\n");
    }
    return 0;
}