class Solution {
   public:
    int dp[1025][10] = {0};
    int vis[1025][10] = {0};
    int dfs(int flag, int lf) {
        if (lf == 0)
            return 1;
        if (vis[flag][lf])
            return dp[flag][lf];
        vis[flag][lf] = 1;
        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            if ((flag & (1 << i)) == 0) {
                ans += dfs(flag | (1 << i), lf - 1);
            }
        }
        return dp[flag][lf] = ans;
    }
    int countSpecialNumbers(int n) {
        int dg[20] = {0}, p = 0;
        while (n) {
            dg[++p] = n % 10;
            n /= 10;
        }
        int flag = 0;
        int ans = 1;  // self
        for (int i = p; i > 0; i--) {
            for (int j = dg[i] - 1; j >= 0; j--) {
                if (j == 0 && i == p)
                    break;
                if (!(flag & (1 << j)))
                    ans += dfs(flag | (1 << j), i - 1);
            }
            if (((1 << dg[i]) & flag)) {
                ans--;  // self
                break;
            }
            flag |= (1 << dg[i]);
        }
        for (int i = p - 1; i > 0; i--) {
            for (int j = 1; j <= 9; j++) {
                ans += dfs((1 << j), i - 1);
            }
        }
        return ans;
    }
};