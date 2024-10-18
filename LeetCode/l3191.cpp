class Solution {
   public:
    int minOperations(vector<int>& nums) {
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] == 0) {
                if (i + 2 < l) {
                    ans++;
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                } else
                    return -1;
            }
        }
        return ans;
    }
};