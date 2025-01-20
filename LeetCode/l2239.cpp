class Solution {
   public:
    int findClosestNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i : nums) {
            if (abs(i) < abs(ans) || (abs(i) == abs(ans) && i > 0))
                ans = i;
        }
        return ans;
    }
};