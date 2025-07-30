class Solution {
   public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = nums[0];
        int ans = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                ans = cnt = 1;
                maxValue = nums[i];
            } else if (nums[i] < maxValue) {
                cnt = 0;
            } else if (nums[i] == maxValue) {
                cnt++;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};
