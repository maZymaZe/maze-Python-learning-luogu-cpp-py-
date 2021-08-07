class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (nums[i] >= 0)
                break;
            if (nums[i] < 0)
                nums[i] = -nums[i], cnt++;
            if (cnt == k)
                break;
                }
        if (cnt == k || (k - cnt) % 2 == 0) {
            int ans = 0;
            for (int i = 0; i < l; i++)
                ans += nums[i];
            return ans;
        }
        int mi = 0x3f3f3f3f, mip = -1;
        for (int i = 0; i < l; i++) {
            if (nums[i] < mi)
                mi = nums[i], mip = i;
        }
        nums[mip] = -nums[mip];
        int ans = 0;
        for (int i = 0; i < l; i++)
            ans += nums[i];
        return ans;
    }
};