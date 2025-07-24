class Solution {
   public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pre = -1000;
        int ans = 0, t = 0;
        for (int i : nums) {
            if (i >= 0 && i != pre) {
                ans += i;
                t = 1;
            }
            pre = i;
        }
        return t ? ans : nums[nums.size() - 1];
    }
};