class Solution {
   public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n != 1) {
            int m = n / 2;
            for (int i = 0; i < m; i++) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                } else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }
            n = m;
        }
        return nums[0];
    }
};
