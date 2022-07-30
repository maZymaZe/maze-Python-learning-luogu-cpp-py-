class Solution {
   public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ls = s.size();
        vector<vector<int>> dp(ls + 1);
        dp[ls] = vector<int>(26, 0x3f3f3f3f);
        for (int i = ls - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            dp[i][s[i] - 'a'] = i;
        }
        int ans = 0;
        for (auto& x : words) {
            int p = 0;
            for (auto c : x) {
                if (p > ls)
                    break;
                p = dp[p][c - 'a'] + 1;
            }
            ans += (p < 0x3f3f3f3f);
        }
        return ans;
    }
};