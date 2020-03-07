#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int cmp(const int &a, const int &b)
{
    return a > b;
}
int mi[100005], s[100005], d2[100005], len2 = 1, ps = 1, n = 0, ans = 0, now = 0;
int main()
{
    while (cin >> mi[++n])
        ;
    n--;
    s[1] = mi[1];
    d2[1] = mi[1];
    for (int i = 2; i <= n; i++)
    {
        if (mi[i] <= s[ps])
        {
            ps++;
            s[ps] = mi[i];
        }
        else
        {
            if (s[1] < mi[i])
                s[1] = mi[i];
            else
            {
                int p = upper_bound(s + 1, s + 1 + ps, mi[i], cmp) - s;
                s[p] = mi[i];
            }
        }
        if (d2[len2] < mi[i])
            d2[++len2] = mi[i];
        else
        {
            int p2 = lower_bound(d2 + 1, d2 + 1 + len2, mi[i]) - d2;
            d2[p2] = mi[i];
        }
    }
    printf("%d\n%d", ps, len2);

    return 0;
}