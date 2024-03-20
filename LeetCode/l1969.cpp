class Solution {
   public:
    int MOD = 1e9 + 7;
    long long qpow(long long a, long long b) {
        long long ans = 1;
        while (b) {
            if (b & 1)
                ans = ans * a % MOD;
            a = a * a % MOD;
            b /= 2;
        }
        return ans;
    }
    int minNonZeroProduct(int p) {
        long long z = (1ll << p) - 1;
        long long x = z - 1;
        long long y = x / 2;
        x %= MOD;
        z %= MOD;
        long long res = qpow(x, y);
        return res * z % MOD;
    }
};