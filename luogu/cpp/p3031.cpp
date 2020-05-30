#include <cstdio>
int n, x, a[100005], s[100005] = {0};
int tr[300005] = {0};
int lowbit(int x) { return x & (-x); }
long long res = 0;
void update(int x, int v)
{
    while (x <= n + 130000)
    {
        tr[x] += v;
        x += lowbit(x);
    }
}
long long qs(int x)
{
    if (x == 0)
        return 0;
    long long ans = 0;
    while (x > 0)
    {
        ans += tr[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + ((a[i] >= x) ? 1 : -1);
    }
    update(130000,1);
    for (int i = 1; i <= n; i++)
    {
        res = res + qs(s[i] + 130000);
        update(130000 + s[i], 1);
    }
    printf("%lld", res);
    return 0;
}