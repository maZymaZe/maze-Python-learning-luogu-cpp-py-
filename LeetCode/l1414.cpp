class Solution {
   public:
    int findMinFibonacciNumbers(int k) {
        long long f[100] = {0};
        f[1] = 1, f[2] = 1;
        for (int i = 3; i < 60; i++)
            f[i] = f[i - 1] + f[i - 2];
        int ans = 0;
        for (int i = 59; i >= 1; i--) {
            if (k && f[i] <= k) {
                ans += k / f[i];
                k %= f[i];
            }
        }
        return ans;
    }
};