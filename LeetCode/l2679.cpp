class Solution {
   public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& v : nums) {
            sort(v.begin(), v.end());
        }
        int n = nums.size(), m = nums[0].size(), ans = 0;
        for (int i = m - 1; i >= 0; i--) {
            int ma = nums[0][i];
            for (int j = 1; j < n; j++)
                ma = max(ma, nums[j][i]);
            ans += ma;
        }
        return ans;
    }
};