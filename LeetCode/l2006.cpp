class Solution {
   public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            ans += mp[nums[i] + k] + mp[nums[i] - k];
            mp[nums[i]]++;
        }
        return ans;
    }
};