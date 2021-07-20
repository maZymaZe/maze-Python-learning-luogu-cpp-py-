class Solution {
   public:
    int minPairSum(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int m = l / 2, ans = nums[0] + nums[l - 1];
        for (int i = 1; i < m; i++) {
            ans = max(ans, nums[i] + nums[l - i - 1]);
        }
        return ans;
    }
};