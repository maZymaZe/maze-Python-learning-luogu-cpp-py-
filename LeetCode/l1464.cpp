class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size();
        nth_element(nums.begin(), nums.begin() + l - 2, nums.end());
        return (nums[l - 1] - 1) * (nums[l - 2] - 1);
    }
};