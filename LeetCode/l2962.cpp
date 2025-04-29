class Solution {
   public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = 0, l = 0, n = nums.size(), cur = 0;
        for (int i : nums)
            mx = max(mx, i);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == mx)
                cur++;
            while (cur >= k) {
                if (nums[l] == mx)
                    cur--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};