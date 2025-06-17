class Solution {
   public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            }
            res.emplace_back(nums.begin() + i, nums.begin() + i + 3);
        }
        return res;
    }
};
