class Solution {
   public:
    int maxAscendingSum(vector<int>& nums) {
        int l = nums.size(), ans = nums[0], tot = nums[0];
        for (int i = 1; i < l; i++) {
            if (nums[i] > nums[i - 1])
                tot += nums[i];
            else
                tot = nums[i];
            ans = max(ans, tot);
        }
        return ans;
    }
};