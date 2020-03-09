#include <cstdio>
#include <algorithm>
using namespace std;
int ma[404][404], mi[404][404], n, s[404][404], mx = 0, mn = 999999999;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i][i]);
        s[i + n][i + n] = s[i][i];
        //s[i][i]=mi[i][i]=ma[i][i];
    }
    for (int i = 1; i <= 2 * n - 1; i++)
        for (int j = 1; j <= 2 * n - i; j++)
            s[j][j + i] = s[j][j + i - 1] + s[j + i][j + i];

    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= 2 * n - i; j++)
        {
            mi[j][j + i] = 999999999;
            for (int k = 1; k <= i; k++)
            {
                ma[j][j + i] = max(ma[j][j + k - 1] + ma[j + k][j + i], ma[j][j + i]);
                mi[j][j + i] = min(mi[j][j + k - 1] + mi[j + k][j + i], mi[j][j + i]);
            }
            ma[j][j + i] += s[j][j + i];
            mi[j][j + i] += s[j][j + i];
        }
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, ma[i][i + n - 1]);
        mn = min(mn, mi[i][i + n - 1]);
    }
    printf("%d\n%d", mn, mx);
    return 0;
}