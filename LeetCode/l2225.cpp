class Solution {
   public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        for (const auto& i : matches) {
            mp[i[0]] += 0, mp[i[1]] += 1;
        }
        vector<vector<int>> ans(2);
        for (const auto& i : mp) {
            if (i.second < 2)
                ans[i.second].push_back(i.first);
        }
        return ans;
    }
};