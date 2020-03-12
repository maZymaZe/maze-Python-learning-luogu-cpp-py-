#include <cstdio>
#include <algorithm>
using namespace std;
struct dish
{
    int a, b, c;
} d[60];
int t, n;
long long dp[100005] = {0}, ans = 0;
int cmp(const dish &p, const dish &q)
{
    return 1.0 * p.b / p.c > 1.0 * q.b / q.c;
}
int main()
{
    scanf("%d%d", &t, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i].a);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i].b);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i].c);
    }
    sort(d + 1, d + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (j + d[i].c <= t)
                dp[j + d[i].c] = max((long long)dp[j] + d[i].a - (long long)d[i].b * (j + d[i].c),
                                     (long long)dp[j + d[i].c]);
        }
    }
    for (int i = 0; i <= t; i++)
        ans = max(ans, dp[i]);
    printf("%lld", ans);
    return 0;
}