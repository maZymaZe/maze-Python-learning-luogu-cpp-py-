class Solution {
   public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mp(n + 2, vector<int>(n + 2));
        vector<vector<int>> dp1 = mp, dp2 = mp, dp3 = mp, dp4 = mp;
        int l = mines.size();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mp[i][j] = 1;
        for (int i = 0; i < l; i++)
            mp[mines[i][0] + 1][mines[i][1] + 1] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (mp[i][j - 1]) {
                    dp1[i][j] = dp1[i][j - 1] + 1;
                }
                if (mp[i - 1][j]) {
                    dp2[i][j] = dp2[i - 1][j] + 1;
                }
            }
        for (int i = n; i > 0; i--)
            for (int j = n; j > 0; j--) {
                if (mp[i][j + 1]) {
                    dp3[i][j] = dp3[i][j + 1] + 1;
                }
                if (mp[i + 1][j]) {
                    dp4[i][j] = dp4[i + 1][j] + 1;
                }
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (mp[i][j])
                    ans = max(ans, 1 + min({dp1[i][j], dp2[i][j], dp3[i][j],
                                            dp4[i][j]}));
            }
        return ans;
    }
};