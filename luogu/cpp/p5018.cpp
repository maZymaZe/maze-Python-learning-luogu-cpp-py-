#include <cstdio>
int n, v[1000006], s[1000006][2], sz[1000006];
void dfs(int u)
{
    sz[u] = 1;
    if (s[u][0] != -1)
    {
        dfs(s[u][0]);
        sz[u] += sz[s[u][0]];
    }
    if (s[u][1] != -1)
    {
        dfs(s[u][1]);
        sz[u] += sz[s[u][1]];
    }
}
int ck(int u, int w)
{
    if (u == -1 && w == -1)
        return 1;
    if (u != -1 && w != -1 && v[u] == v[w] && ck(s[u][0], s[w][1]) && ck(s[w][0], s[u][1]))
        return 1;
    return 0;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &s[i][0], &s[i][1]);
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ck(s[i][0], s[i][1]))
            if (sz[i] > ans)
                ans = sz[i];
       
    }
    printf("%d", ans);
    return 0;
}