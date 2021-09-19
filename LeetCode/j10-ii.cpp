class Solution {
   public:
    int numWays(int n) {
        int a[2] = {1, 1}, MOD = 1e9 + 7;
        for (int i = 2; i <= n; i++)
            a[i % 2] = (a[0] + a[1]) % MOD;
        return a[n % 2];
    }
};