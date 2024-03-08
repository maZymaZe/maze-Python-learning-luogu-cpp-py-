class Solution {
   public:
    int minimumPossibleSum(int n, int target) {
        if (n == 1)
            return 1;
        int s1 = min(target / 2, n);
        long long ans = 0, MOD = 1e9 + 7;
        ans += (long long)(1 + s1) * s1 / 2;
        n -= s1;
        ans %= MOD;
        ans += (long long)((long long)target + target + n - 1) * n / 2;
        ans %= MOD;
        return ans;
    }
};