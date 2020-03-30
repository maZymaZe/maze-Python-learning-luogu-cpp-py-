#include <cstdio>
struct treenode
{
    int fa, l, r, dp;
} node[120];
int n, u, v, md = 0, w[120], l1[120], l2[120], p1 = 0, p2 = 0, t, mw = 0;
int main()
{
    scanf("%d", &n);
    node[1].dp = 1;
    node[1].fa = 0;
    w[1] = 1;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        if (node[u].l == 0)
            node[u].l = v;
        else
            node[u].r = v;
        node[v].fa = u;
        node[v].dp = node[u].dp + 1;
        w[node[v].dp]++;
        if (node[v].dp > md)
            md = node[v].dp;
    }
    scanf("%d%d", &u, &v);
    if (u != v)
    {
        t = u;
        l1[0] = u;
        while (t != 0)
        {
            t = node[t].fa;
            p1++;
            l1[p1] = t;
        }

        t = v;
        l2[0] = v;
        while (t != 0)
        {
            t = node[t].fa;
            p2++;
            l2[p2] = t;
        }
        while (l1[p1] == l2[p2])
        {
            p1--;
            p2--;
        }
        for (int i = 1; i <= 102; i++)
        {
            if (w[i] > mw)
                mw = w[i];
        }
    }
    else p1=-1,p2=-1;
    printf("%d\n%d\n%d", md, mw, 2 * (p1 + 1) + p2 + 1);

    return 0;
}