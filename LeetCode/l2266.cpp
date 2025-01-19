class Solution {
   public:
    int countTexts(string pressedKeys) {
        long long dp[2][100003] = {0};
        const int MOD = 1e9 + 7;
        int l = pressedKeys.size();
        dp[0][0] = 1;
        dp[1][0] = 1;
        for (int i = 1; i <= l; i++) {
            if (i - 1 >= 0)
                dp[0][i] += dp[0][i - 1];
            if (i - 2 >= 0)
                dp[0][i] += dp[0][i - 2];
            if (i - 3 >= 0)
                dp[0][i] += dp[0][i - 3];
            dp[0][i] %= MOD;
        }
        for (int i = 1; i <= l; i++) {
            if (i - 1 >= 0)
                dp[1][i] += dp[1][i - 1];
            if (i - 2 >= 0)
                dp[1][i] += dp[1][i - 2];
            if (i - 3 >= 0)
                dp[1][i] += dp[1][i - 3];
            if (i - 4 >= 0)
                dp[1][i] += dp[1][i - 4];
            dp[1][i] %= MOD;
        }
        long long ans = 1;
        char pre = pressedKeys[0];
        int cnt = 1;
        for (int i = 1; i < l; i++) {
            if (pressedKeys[i] != pre) {
                if (pre == '7' || pre == '9') {
                    ans *= dp[1][cnt];
                } else {
                    ans *= dp[0][cnt];
                }
                ans %= MOD;
                cnt = 1;
                pre = pressedKeys[i];
            } else
                cnt++;
        }
        if (pre == '7' || pre == '9') {
            ans *= dp[1][cnt];
        } else {
            ans *= dp[0][cnt];
        }
        ans %= MOD;
        return ans;
    }
};