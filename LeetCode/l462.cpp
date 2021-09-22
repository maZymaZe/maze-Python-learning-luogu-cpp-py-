class Solution {
   public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + (nums.size() / 2), nums.end());
        int ans = 0, m = nums[nums.size() / 2];
        for (auto x : nums)
            ans += abs(m - x);
        return ans;
    }
};