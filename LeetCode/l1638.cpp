class Solution {
   public:
    int countSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp0(n + 1, vector<int>(m + 1));
        auto dp1 = dp0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp0[i + 1][j + 1] = (s[i] == t[j] ? (dp0[i][j] + 1) : 0);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp1[i][j] = (s[i] == t[j] ? (dp1[i + 1][j + 1] + 1) : 0);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i] != t[j]) {
                    ans += (dp0[i][j] + 1) * (dp1[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};