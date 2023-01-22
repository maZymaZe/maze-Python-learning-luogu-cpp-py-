class Solution {
   public:
    int cnt[10] = {0}, n;
    unordered_map<long long, int> dp, rs;
    int dfs(long long s) {
        int r = rs[s], ans = 0;
        if (dp.count(s))
            return dp[s];
        if (s == 0)
            return 0;
        for (int i = 1; i < n; i++) {
            if (s & (0x1fll << (i * 5 - 5))) {
                long long ns = s - (1ll << (i * 5 - 5));
                rs[ns] = (r + n - i) % n;
                ans = max(ans, (r == 0) + dfs(ns));
            }
        }
        return dp[s] = ans;
    }
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        n = batchSize;
        for (auto i : groups)
            cnt[i % batchSize]++;

        long long x = 0;
        for (int i = 1; i < n; i++) {
            x |= (((long long)cnt[i]) << (i * 5 - 5));
        }
        rs[x] = 0;
        return dfs(x) + cnt[0];
    }
};