#include <cstdio>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int dp[30005], p[26], v[26], n, ans, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &p[i], &v[i]);
        v[i] *= p[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= p[i]; j--)
        {
            dp[j] = max(dp[j - p[i]] + v[i], dp[j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);
    return 0;
}
