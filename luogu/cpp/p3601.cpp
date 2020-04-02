#include <cstdio>
#define MAX 1000006
#define MOD 666623333
int isprime[MAX];
long long ans = 0, l, r, prime[MAX], A[MAX], B[MAX];
int pp = 0;
void shai()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (!isprime[i])
        {
            prime[++pp] = i;
            for (int j = 2 * i; j < 1000000; j += i)
            {
                isprime[j] = 1;
            }
        }
    }
}
void work()
{
    int i = 1;
    while (prime[i] * prime[i] <= r)
    {
        long long p = prime[i];
        for (int x = (p - l % p) % p; x <= r - l; x += p)
        {
            A[x] /= p, A[x] *= p - 1;
            while (B[x] % p == 0)
                B[x] /= p;
        }
        i++;
    }
}
int main()
{
    shai();
    scanf("%lld%lld", &l, &r);
    for (long long i = l; i <= r; i++)
    {
        A[i - l] = i;
        B[i - l] = i;
    }
    work();
    for (int i = 0; i <= r - l; i++)
    {
        if (B[i] != 1)
            A[i] /= B[i], A[i] *= (B[i] - 1);
        ans = (ans + i + l - A[i]) % MOD;
    }
    printf("%lld", ans);
    return 0;
}