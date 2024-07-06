class Solution {
   public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l = nums.size(), pre = nums[0], cnt = 1;
        long long ans = 0;
        for (int i = 1; i < l; i++) {
            if (pre == nums[i]) {
                ans += (long long)cnt * (cnt + 1) / 2;
                cnt = 1;
            } else
                cnt++, pre ^= 1;
        }
        ans += (long long)cnt * (cnt + 1) / 2;
        return ans;
    }
};