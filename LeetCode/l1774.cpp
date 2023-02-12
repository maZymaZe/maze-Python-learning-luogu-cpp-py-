class Solution {
   public:
    int closestCost(vector<int>& baseCosts,
                    vector<int>& toppingCosts,
                    int target) {
        int n = baseCosts.size(), m = toppingCosts.size();
        vector<int> dp((int)(2e5 + 1));
        int mi = 2e5;
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = mi; j > 0; j--) {
                if (j >= toppingCosts[i])
                    dp[j] |= dp[j - toppingCosts[i]];
                if (j >= toppingCosts[i] * 2)
                    dp[j] |= dp[j - toppingCosts[i] * 2];
            }
        }
        int dis = 0x3f3f3f3f, ans = 0;
        for (int i = 0; i <= mi; i++) {
            if (dp[i]) {
                for (int j = 0; j < n; j++) {
                    int tot = i + baseCosts[j];
                    int dd = abs(tot - target);
                    if (dd < dis) {
                        ans = tot;
                    } else if (dd == dis) {
                        ans = min(ans, tot);
                    }
                    dis = min(dis, dd);
                }
            }
        }
        return ans;
    }
};