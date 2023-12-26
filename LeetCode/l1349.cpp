class Solution {
   public:
    int maxStudents(vector<vector<char>>& seats) {
        int n = seats.size(), m = seats[0].size();
        int st = (1 << n);
        vector<vector<int>> nx(st);
        for (int i = 0; i < st; i++) {
            for (int j = 0; j < st; j++) {
                int ok = 1;
                for (int k = 0; k < n; k++) {
                    if ((1 << k) & i) {
                        if ((1 << k) & j)
                            ok = 0;
                        if (k && ((1 << (k - 1)) & j))
                            ok = 0;
                        if (k + 1 < n && ((1 << (k + 1)) & j))
                            ok = 0;
                    }
                }
                if (ok)
                    nx[i].push_back(j);
            }
        }
        vector<vector<int>> dp(st, vector<int>(2));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < st; j++) {
                int ok = 1, tot = 0;
                dp[j][i & 1] = 0;
                for (int k = 0; k < n; k++) {
                    if (j & (1 << k)) {
                        if (seats[k][i] == '#')
                            ok = 0;
                        else
                            tot++;
                    }
                }
                if (!ok)
                    continue;
                for (int k : nx[j]) {
                    dp[j][i & 1] = max(dp[j][i & 1], dp[k][(i & 1) ^ 1] + tot);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < st; i++) {
            ans = max(ans, dp[i][(m & 1) ^ 1]);
        }
        return ans;
    }
};