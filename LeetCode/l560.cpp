class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, l = nums.size(), ps = 0;
        for (int i = 0; i < l; i++) {
            ps += nums[i];
            if (mp.count(ps - k))
                ans += mp[ps - k];
            mp[ps]++;
        }
        return ans;
    }
};