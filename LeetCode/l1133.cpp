class Solution {
   public:
    int largestUniqueNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        for (int i = l - 1; i >= 0; i--) {
            if ((i == l - 1 || nums[i] != nums[i + 1]) &&
                (i == 0 || nums[i - 1] != nums[i]))
                return nums[i];
        }
        return -1;
    }
};