class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int l = nums.size(), p = nums[0] + 1, ans = 0;
        for (int i = 1; i < l; i++)
            ans += max(0, p - nums[i]), p = max(p, nums[i]) + 1;
        return ans;
    }
};