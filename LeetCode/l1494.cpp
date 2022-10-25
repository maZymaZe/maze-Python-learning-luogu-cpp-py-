class Solution {
   public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prerq(n);
        for (auto& it : relations) {
            prerq[it[1] - 1] |= (1 << (it[0] - 1));
        }
        vector<int> setmask(1 << n), valid(1 << n);
        int lim = (1 << n);
        for (int m = 0; m < lim; m++) {
            if (__builtin_popcount(m) <= k) {
                for (int i = 0; i < n; i++) {
                    if (m & (1 << i))
                        setmask[m] |= prerq[i];
                }
                valid[m] = ((setmask[m] & m) == 0);
            }
        }
        vector<int> dp(1 << n, 0x3f3f3f3f);
        dp[0] = 0;
        for (int m = 0; m < lim; m++) {
            for (int s = m; s; s = (s - 1) & m) {
                if (valid[s] && ((m & setmask[s]) == setmask[s])) {
                    dp[m] = min(dp[m], dp[m ^ s] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};