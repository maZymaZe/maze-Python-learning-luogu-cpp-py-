class Solution {
   public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int pre = lower - 1;
        nums.push_back(upper + 1);
        int l = nums.size();
        vector<string> ans;
        for (int i = 0; i < l; i++) {
            if (nums[i] - pre == 2) {
                ans.push_back(to_string(nums[i] - 1));
            } else if (nums[i] - pre > 2) {
                ans.push_back(to_string(pre + 1) + "->" +
                              to_string(nums[i] - 1));
            }
            pre = nums[i];
        }
        return ans;
    }
};