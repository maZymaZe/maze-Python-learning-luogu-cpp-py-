class Solution {
   public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        vector<int> c;
        for (auto x : mp)
            c.push_back(x.second);

        int n = c.size(), m = quantity.size();
        int lim = 1 << m;
        vector<int> sum(lim, 0);
        for (int i = 1; i < lim; i++) {
            for (int j = 0; j < m; j++) {
                if ((i & (1 << j)) != 0) {
                    int l = i - (1 << j);
                    sum[i] = sum[l] + quantity[j];
                    break;
                }
            }
        }

        vector<vector<bool>> dp(n, vector<bool>(1 << m, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < lim; j++) {
                if (i > 0 && dp[i - 1][j]) {
                    dp[i][j] = true;
                    continue;
                }

                for (int s = j; s != 0; s = ((s - 1) & j)) {
                    int prev = j - s;
                    bool lst = (i == 0) ? (prev == 0) : dp[i - 1][prev];
                    bool nd = (sum[s] <= c[i]);
                    if (lst && nd) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
        }
        return dp[n - 1][lim - 1];
    }
};