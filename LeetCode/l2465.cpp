class Solution {
   public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        l /= 2;
        for (int i = 0; i < l; i++) {
            nums[i] += nums[2 * l - i - 1];
        }
        sort(nums.begin(), nums.begin() + l);
        return (unique(nums.begin(), nums.begin() + l) - nums.begin());
    }
};