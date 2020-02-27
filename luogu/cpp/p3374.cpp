#include <cstdio>
int a[500005], c[500005];
int op, l, r, n, m, t;
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int v)
{
    a[x] += v;
    while (x <= n)
    {
        c[x] += v;
        x += lowbit(x);
    }
}
long long finds(int x)
{
    if (x == 0)
        return 0;
    else
    {
        long long ans = 0;
        while (x > 0)
        {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        update(i, t);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1)
            update(l, r);
        else
        {
            printf("%lld\n", finds(r) - finds(l - 1));
        }
    }
    return 0;
}