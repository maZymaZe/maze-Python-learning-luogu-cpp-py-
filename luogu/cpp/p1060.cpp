#include <cstdio>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int dp[26][30001], p[26], v[26], n, t1, t2, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &p[i], &v[i]);
        v[i] *= p[i];
    }
    for (int j = 0; j <= n; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            if (j >= p[i])
                dp[i][j] = max(dp[i-1][j - p[i]] + v[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[m][n]);
    return 0;
}