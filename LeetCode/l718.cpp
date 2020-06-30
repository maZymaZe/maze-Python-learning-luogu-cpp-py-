class Solution {
   public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size(), lb = B.size(), res = 0;
        vector<vector<int>> dp(la + 1, vector<int>(lb + 1));
        for (int i = 1; i <= la; i++) {
            for (int j = 1; j <= lb; j++) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};