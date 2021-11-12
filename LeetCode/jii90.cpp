class Solution {
   public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
            return 0;
        if (l == 1)
            return nums[0];
        if (l == 2)
            return max(nums[1], nums[0]);
        vector<int> dp1(l), dp2(l);
        int ans = 0;
        dp1[0] = nums[0];
        dp1[1] = nums[1];
        for (int i = 2; i < l - 1; i++) {
            if (i > 2)
                dp1[i] = max(dp1[i - 2], dp1[i - 3]);
            else
                dp1[i] = dp1[i - 2];
            dp1[i] += nums[i];
        }
        ans = max(dp1[l - 2], dp1[l - 3]);
        dp2[1] = nums[1];
        dp2[2] = nums[2];
        for (int i = 3; i < l; i++) {
            if (i > 3)
                dp2[i] = max(dp2[i - 2], dp2[i - 3]);
            else
                dp2[i] = dp2[i - 2];
            dp2[i] += nums[i];
        }
        ans = max(ans, dp2[l - 1]);
        ans = max(ans, dp2[l - 2]);
        return ans;
    }
};