class Solution {
   public:
    int nthMagicalNumber(int n, int a, int b) {
        int base = __gcd(a, b);
        a /= base, b /= base;
        if (a > b)
            swap(a, b);
        long long c = (long long)a * b;
        long long cnt = a + b - 1;
        long long d = n / cnt, MOD = 1e9 + 7;
        n %= cnt;
        long long ans = d * c % MOD;
        long long ta = 0, tb = 0, nx = 0;
        while (ta < c && tb < c && n) {
            long long na = ta + a, nb = tb + b;
            if (na <= nb) {
                nx = na;
                ta = na;
            } else {
                nx = nb;
                tb = nb;
            }
            n--;
        }
        ans = ans + nx;
        ans %= MOD;
        ans = ans * base % MOD;
        return ans;
    }
};