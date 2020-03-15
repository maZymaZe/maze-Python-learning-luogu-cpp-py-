#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
struct rubbish
{
    int t, h, f;
    friend bool operator<(rubbish a, rubbish b)
    {
        return a.t < b.t;
    }
} r[1001];
int dp[120][1020], d, n;
int main()
{
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &r[i].t, &r[i].f, &r[i].h);
    }
    sort(r + 1, r + 1 + n);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 10;
    r[0].f = r[0].h = r[0].t = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= d; j++)
        {
            if (dp[i][j] >= 0)
            {
                if (j + r[i + 1].h >= d && dp[i][j] >= r[i + 1].t - r[i].t)
                {
                    printf("%d", r[i + 1].t);
                    exit(0);
                }
                if (dp[i][j] - r[i + 1].t + r[i].t >= 0)
                    dp[i + 1][j + r[i + 1].h] = dp[i][j] - r[i + 1].t + r[i].t;
                if (dp[i][j] - r[i + 1].t + r[i].t >= 0)
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - r[i + 1].t + r[i].t + r[i + 1].f);
            }
        }

    int m = 10, s = 0;
    for (int k = 1; k <= n; k++)
    {
        if (r[k].t - r[k - 1].t > m)
        {
            printf("%d", m + s);
            exit(0);
        }
        else
        {
            m = m + r[k].f + r[k - 1].t - r[k].t;
            s += r[k].t - r[k - 1].t;
        }
    }
    printf("%d", m + s);
    return 0;
}