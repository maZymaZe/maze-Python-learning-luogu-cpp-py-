class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int f = 1, l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] != f) {
                f ^= 1;
                ans++;
            }
        }
        return ans;
    }
};