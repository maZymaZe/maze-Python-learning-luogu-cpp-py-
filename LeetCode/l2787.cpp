class Solution {
   public:
    long long dp[400][400] = {0}, pp[400] = {0};
    int vis[400][400] = {0};
    int mod = 1e9 + 7;
    int X;
    long long f(int n, int mi) {
        if (vis[n][mi])
            return dp[n][mi];
        vis[n][mi] = 1;
        long long ans = 0;
        for (int i = mi + 1; i <= n; i++) {
            long long y = pp[i];
            if (y > n)
                break;
            else if (y == n) {
                ans++;
                ans = ans % mod;
            } else {
                ans = ans + f(n - y, i);
                ans = ans % mod;
            }
        }
        dp[n][mi] = ans;
        return ans;
    }
    int numberOfWays(int n, int x) {
        X = x;
        for (int i = 0; i <= n; i++) {
            pp[i] = pow(i, x);
        }
        return f(n, 0);
    }
};