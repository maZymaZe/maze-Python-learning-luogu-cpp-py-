class Solution {
   public:
    long long maxStrength(vector<int>& nums) {
        int l = nums.size();
        if (l == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        int tmp = 1, mc = 0;
        long long ans = 1;
        for (int i = 0; i < l; i++) {
            if (nums[i] < 0) {
                mc++;
                if (tmp == 1)
                    tmp = nums[i];
                else {
                    ans *= nums[i];
                    ans *= tmp;
                    tmp = 1;
                }
            } else if (nums[i] > 1) {
                ans *= nums[i];
            }
        }
        if (mc <= 1 && nums[l - 1] == 0) {
            return 0;
        }

        return ans;
    }
};