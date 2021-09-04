class Solution {
   public:
    int dp[302][302] = {0};
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]),
                                       dp[i - 1][j - 1]) +
                                   1;
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans * ans;
    }
};