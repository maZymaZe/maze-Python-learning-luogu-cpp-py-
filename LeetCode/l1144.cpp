class Solution {
   public:
    int movesToMakeZigzag(vector<int>& nums) {
        int ans1 = 0, ans2 = 0, l = nums.size();
        if(l<2)return 0;
        for (int i = 0; i < l; i++) {
            if (i & 1) {
                if (i == l - 1) {
                    if (nums[i] >= nums[i - 1]) {
                        ans2 += nums[i] - nums[i - 1] + 1;
                    }
                } else {
                    if (nums[i] >= nums[i - 1] || nums[i] >= nums[i + 1]) {
                        ans2 += nums[i] - min(nums[i + 1], nums[i - 1]) + 1;
                    }
                }
            } else {
                if (i == 0) {
                    if (nums[i] >= nums[i + 1]) {
                        ans1 += nums[i] - nums[i + 1] + 1;
                    }
                } else if (i == l - 1) {
                    if (nums[i] >= nums[i - 1]) {
                        ans1 += nums[i] - nums[i - 1] + 1;
                    }
                } else {
                    if (nums[i] >= nums[i - 1] || nums[i] >= nums[i + 1]) {
                        ans1 += nums[i] - min(nums[i + 1], nums[i - 1]) + 1;
                    }
                }
            }
        }

        return min(ans1, ans2);
    }
};