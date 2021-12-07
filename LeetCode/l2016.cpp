class Solution {
   public:
    int maximumDifference(vector<int>& nums) {
        int l = nums.size(), ans = -1, mi = nums[0];
        for (int i = 1; i < l; i++) {
            if (nums[i] > mi) {
                ans = max(ans, nums[i] - mi);
            }
            mi = min(mi, nums[i]);
        }
        return ans;
    }
};