class Solution {
   public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int l = nums.size(), ans = 1;
        for (int i = 0; i < l; i++) {
            mp[nums[i]].push_back(i);
        }
        for (const auto& pr : mp) {
            const auto& v = pr.second;
            int len = v.size(), ll = 0, rr = 0;
            while (ll < len && rr < len) {
                while (rr < len && v[rr] - v[ll] <= k + rr - ll) {
                    ans = max(ans, rr - ll + 1);
                    rr++;
                }
                ll++;
            }
        }
        return ans;
    }
};