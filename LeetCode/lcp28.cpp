class Solution {
   public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size(), ans = 0, MOD = 1e9 + 7;
        for (int i = 1; i < l; i++) {
            ans +=
                (upper_bound(nums.begin(), nums.begin() + i, target - nums[i]) -
                 nums.begin());
            ans %= MOD;
        }
        return ans;
    }
};