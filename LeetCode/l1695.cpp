class Solution {
   public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = 0;
        int c[10001] = {0}, ans = 0, sum = 0;
        while (r < len) {
            c[nums[r]]++;
            if (c[nums[r]] == 2) {
                while (c[nums[r]] == 2) {
                    c[nums[l]]--;
                    sum -= nums[l];
                    l++;
                }
            }
            sum += nums[r];
            r++;
            ans = max(ans, sum);
        }
        return ans;
    }
};