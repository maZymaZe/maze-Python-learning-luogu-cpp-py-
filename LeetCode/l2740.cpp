class Solution {
   public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 1e9 + 7, l = nums.size();
        for (int i = 1; i < l; i++)
            ans = min(ans, nums[i] - nums[i - 1]);
        return ans;
    }
};