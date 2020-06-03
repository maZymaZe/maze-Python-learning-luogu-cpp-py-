#include <cstdio>
int max(int a, int b) { return a > b ? a : b; }
int n, s[110][110], s1[110][110], t[110], ans = 0, x, y, mx, my;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        mx = max(mx, x);
        my = max(my, y);
        s1[x][y]++;
        s[x][y]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        for (int j = 1; j <= my; j++)
        {
            s[i][j] += s[i - 1][j];
            s1[i][j] += s1[i][j - 1];
        }
    }
    for (int l = 1; l <= mx; l++)
    {
        for (int r = l; r <= mx; r++)
        {

            for (int i = 1; i <= my; i++)
            {
                t[i] = s[r - 1][i] - s[l][i];
            }
            int d = 1;
            for (int i = 1; i <= my; i++)
            {
                int get = t[d] + t[i] + s1[l][i] - s1[l][d - 1] + s1[r][i] - s1[r][d-1];
                ans = max(ans, get);
                if (t[i] > t[d] + s1[l][i - 1] - s1[l][d - 1] + s1[r][i - 1]-s1[r][d - 1])
                    d = i;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
