class Solution {
   public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(requirements.begin(), requirements.end(), cmp);
        int l = requirements.size(), p = 0, MOD = 1e9 + 7;
        vector<int> dp[2] = {vector<int>(500), vector<int>(500)};
        dp[1][0] = 1;
        for (int i = 0; i < n; i++) {
            fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
            if (p < l && requirements[p][0] == i) {
                for (int j = 0; j <= i; j++) {
                    if (requirements[p][1] - j >= 0) {
                        dp[i & 1][requirements[p][1]] +=
                            dp[(i & 1) ^ 1][requirements[p][1] - j];
                        dp[i & 1][requirements[p][1]] %= MOD;
                    } else
                        break;
                }
                p++;
            } else {
                for (int j = 0; j <= 400; j++) {
                    if (dp[(i & 1) ^ 1][j]) {
                        for (int k = 0; k <= i; k++) {
                            if (j + k <= 400) {
                                dp[i & 1][j + k] += dp[(i & 1) ^ 1][j];
                                dp[i & 1][j + k] %= MOD;
                            } else
                                break;
                        }
                    }
                }
            }
        }
        return dp[(n - 1) & 1][requirements[l - 1][1]];
    }
};