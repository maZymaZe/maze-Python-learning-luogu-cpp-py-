class Solution {
   public:
    long long mod = 1e9 + 7;
    long long qpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        return qpow(5, (n + 1) / 2) * qpow(4, n / 2) % mod;
    }
};