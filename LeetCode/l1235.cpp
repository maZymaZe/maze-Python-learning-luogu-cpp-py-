class Solution {
   public:
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {
        map<int, vector<int>> mp;
        for (auto it : startTime) {
            if (!mp.count(it)) {
                mp.insert({it, vector<int>()});
            }
        }
        int l = 0;
        for (auto it : endTime) {
            if (!mp.count(it)) {
                mp.insert({it, vector<int>()});
            }
            mp[it].push_back(l);
            l++;
        }
        int pmx = 0;
        unordered_map<int, int> dp;
        for (auto& it : mp) {
            dp[it.first] = pmx;
            for (auto jt : it.second) {
                dp[it.first] =
                    max(dp[it.first], dp[startTime[jt]] + profit[jt]);
            }
            pmx = max(pmx, dp[it.first]);
        }
        return pmx;
    }
};