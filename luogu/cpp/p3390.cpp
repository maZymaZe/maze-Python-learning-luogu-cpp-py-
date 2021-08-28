#include <cstdio>
#include <cstring>
const int MOD = 1e9 + 7, NMAX = 102;
int n;
long long k;
void Mcopy(int dst[][NMAX], int src[][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dst[i][j] = src[i][j];
        }
    }
}
void Mmul(int a[][NMAX], int b[][NMAX], int c[][NMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] =
                    ((1ll * c[i][j] + 1ll * a[i][k] * b[k][j] % MOD) % MOD +
                     MOD) %
                    MOD;
            }
        }
    }
}
int tt[NMAX][NMAX];
void Mqpow(int a[][NMAX], long long x, int dst[][NMAX]) {
    while (x) {
        if (x & 1) {
            memset(tt, 0, sizeof(tt));
            Mmul(dst, a, tt);
            Mcopy(dst, tt);
        }
        memset(tt, 0, sizeof(tt));
        Mmul(a, a, tt);
        Mcopy(a, tt);
        x >>= 1;
    }
}
int ip[NMAX][NMAX], op[NMAX][NMAX];
int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ip[i][j]);
        }
        op[i][i] = 1;
    }
    Mqpow(ip, k, op);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", op[i][j]);
        printf("\n");
    }
    return 0;
}