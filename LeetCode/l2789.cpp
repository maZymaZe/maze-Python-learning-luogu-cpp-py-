class Solution {
   public:
    long long maxArrayValue(vector<int>& nums) {
        long long cur = nums.back();
        int l = nums.size();
        for (int i = l - 2; i >= 0; i--) {
            if (cur >= nums[i])
                cur += nums[i];
            else
                cur = nums[i];
        }
        return cur;
    }
};