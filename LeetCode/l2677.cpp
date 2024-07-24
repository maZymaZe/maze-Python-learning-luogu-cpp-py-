class Solution {
   public:
    vector<int> relocateMarbles(vector<int>& nums,
                                vector<int>& moveFrom,
                                vector<int>& moveTo) {
        map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        int l = moveFrom.size();
        for (int i = 0; i < l; i++) {
            int t = mp[moveFrom[i]];
            mp[moveFrom[i]] -= t;
            mp[moveTo[i]] += t;
        }
        vector<int> ans;
        for (const auto& m : mp)
            if (m.second)
                ans.push_back(m.first);
        return ans;
    }
};