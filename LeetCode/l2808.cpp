class Solution {
   public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = l / 2;
        for (const auto& pr : mp) {
            const auto& v = pr.second;
            int tl = v.size(), ma = 0;
            if (tl == 1)
                continue;
            for (int i = 0; i + 1 < tl; i++) {
                ma = max((v[i + 1] - v[i]) / 2, ma);
            }
            ma = max(ma, (v[0] + l - v[tl - 1]) / 2);
            ans = min(ma, ans);
        }
        return ans;
    }
};