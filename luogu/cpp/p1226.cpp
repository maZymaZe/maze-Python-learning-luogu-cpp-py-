#include <cstdio>

int main()
{

    long long a, b, c, d, ex[40], cp[40], ans = 1;
    scanf("%lld%lld%lld", &a, &b, &c);
    d = b;
    ex[0] = 1 % c;
    ex[1] = a % c;
    cp[1] = 1;
    for (int i = 2; i <= 38; i++)
    {
        ex[i] = ex[i - 1] * ex[i - 1] % c;
        cp[i] = cp[i - 1] * 2;
    }

    for (int i = 32; i > 0; i--)
    {
        if (b >= cp[i])
        {
            ans *= ex[i];
            ans %= c;
            b -= cp[i];
        }
        if (b == 0)
            break;
    }
    if (d == 0)
        ans = 1 % c;
    printf("%lld^%lld mod %lld=%lld", a, d, c, ans);

    return 0;
}