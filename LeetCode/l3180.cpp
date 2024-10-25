class Solution {
   public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int dp[2002] = {0}, ans = 0;
        dp[0] = 1;
        for (int i = 1; i <= 2000; i++) {
            for (int j = i / 2; j <= i; j++) {
                if (i - j < j && dp[i - j]) {
                    auto tmp = lower_bound(rewardValues.begin(),
                                           rewardValues.end(), j);
                    if (tmp == rewardValues.end() || *tmp != j)
                        continue;
                    dp[i] = 1;
                    ans = max(ans, i);
                    break;
                }
            }
        }
        vector<int> v;
        for (int i = 0; i <= 2000; i++) {
            if (dp[i])
                v.push_back(i);
        }
        for (int i : rewardValues) {
            auto tmp = lower_bound(v.begin(), v.end(), i);
            --tmp;
            ans = max(ans, *tmp + i);
        }
        return ans;
    }
};