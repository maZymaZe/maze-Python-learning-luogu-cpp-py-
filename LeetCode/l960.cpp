class Solution {
   public:
    int minDeletionSize(vector<string>& strs) {
        int dp[102] = {0}, ans = 1, n = strs[0].size(), m = strs.size();
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] + 1 > dp[i]) {
                    int ok = 1;
                    for (int k = 0; k < m; k++) {
                        if (strs[k][i] < strs[k][j]) {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok) {
                        dp[i] = dp[j] + 1;
                        ans = max(ans, dp[i]);
                    }
                }
            }
            if (dp[i] == 0)
                dp[i] = 1;
        }
        return n - ans;
    }
};