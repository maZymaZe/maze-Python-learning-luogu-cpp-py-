class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        int l = nums.size();
        vector<int> ans;
        for (int i = 0; i < l; i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            else
                ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};