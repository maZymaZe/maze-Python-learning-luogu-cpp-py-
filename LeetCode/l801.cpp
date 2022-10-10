class Solution {
   public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int l = nums1.size();
        vector<int> dp[2] = {vector<int>(l, 0x3f3f3f3f),
                             vector<int>(l, 0x3f3f3f3f)};
        dp[0][0] = dp[1][0] = 0;
        if (nums1[0] > nums2[0])
            dp[0][0] = 1;
        if (nums2[0] > nums1[0])
            dp[1][0] = 1;
        for (int i = 1; i < l; i++) {
            int o1 = max(nums1[i - 1], nums2[i - 1]),
                o2 = min(nums1[i - 1], nums2[i - 1]);
            if (nums1[i] > o1 && nums2[i] > o2) {
                if (nums1[i] >= nums2[i]) {
                    dp[1][i] = min(dp[1][i], dp[1][i - 1]);
                }
                if (nums1[i] <= nums2[i]) {
                    dp[0][i] = min(dp[0][i], dp[1][i - 1]);
                }
            }
            if (nums2[i] > o1 && nums1[i] > o2) {
                if (nums1[i] >= nums2[i]) {
                    dp[0][i] = min(dp[0][i], dp[1][i - 1] + 1);
                }
                if (nums1[i] <= nums2[i]) {
                    dp[1][i] = min(dp[1][i], dp[1][i - 1] + 1);
                }
            }
            swap(o1, o2);
            if (nums1[i] > o1 && nums2[i] > o2) {
                if (nums1[i] >= nums2[i]) {
                    dp[1][i] = min(dp[1][i], dp[0][i - 1]);
                }
                if (nums1[i] <= nums2[i]) {
                    dp[0][i] = min(dp[0][i], dp[0][i - 1]);
                }
            }
            if (nums2[i] > o1 && nums1[i] > o2) {
                if (nums1[i] >= nums2[i]) {
                    dp[0][i] = min(dp[0][i], dp[0][i - 1] + 1);
                }
                if (nums1[i] <= nums2[i]) {
                    dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
                }
            }
        }
        return min(dp[0][l - 1], dp[1][l - 1]);
    }
};