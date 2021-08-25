#include <cstdio>
const int NMAX = 1e8 + 10;
int prime[NMAX];
bool isprime[NMAX];
void init(int n) {
    isprime[0] = isprime[1] = 1;
    prime[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (!isprime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int m, q, x;
int main() {
    init(1e8 + 2);
    scanf("%d%d", &m, &q);
    while (q--)
        scanf("%d", &x), printf("%d\n", prime[x]);
    return 0;
}