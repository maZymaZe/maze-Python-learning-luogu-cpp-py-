class Solution {
   public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int p = 0, q = k - 1, ans = 0x3f3f3f3f, l = nums.size();
        while (q < l) {
            ans = min(ans, nums[q++] - nums[p++]);
        }
        return ans;
    }
};