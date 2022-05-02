class Solution {
   public:
    int smallestRangeI(vector<int>& nums, int k) {
        int ma = nums[0], mi = nums[0];
        for (int i : nums)
            ma = max(ma, i), mi = min(mi, i);
        return max(0, ma - mi - k - k);
    }
};