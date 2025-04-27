class Solution {
   public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0, l = nums.size();
        for (int i = 1; i < l - 1; i++) {
            ans += (nums[i] == (nums[i - 1] + nums[i + 1]) * 2);
        }
        return ans;
    }
};