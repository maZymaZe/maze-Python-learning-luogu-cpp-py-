class Solution {
   public:
    vector<int> getTriggerTime(vector<vector<int>>& increase,
                               vector<vector<int>>& requirements) {
        int val[3] = {0};
        int n = increase.size(), m = requirements.size();
        vector<int> ans(m, -1);
        map<int, int> mp[3];
        for (int i = 0; i < 3; i++)
            mp[i][0] = 0, mp[i][0x3f3f3f3f] = 0x3f3f3f3f;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                val[j] += increase[i][j];
                if (!mp[j].count(val[j]))
                    mp[j][val[j]] = i + 1;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++) {
                int d = (mp[j].lower_bound(requirements[i][j]))->second;
                ans[i] = max(ans[i], d);
            }
            if (ans[i] == 0x3f3f3f3f)
                ans[i] = -1;
        }
        return ans;
    }
};