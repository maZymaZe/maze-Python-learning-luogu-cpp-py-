class Solution {
   public:
    vector<int> numberGame(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < l; i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};