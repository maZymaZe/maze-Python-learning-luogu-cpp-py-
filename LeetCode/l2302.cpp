class Solution {
   public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, cur = 0, sum = 0;
        int l = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            cur += sum;
            sum += nums[i];
            cur += (long long)nums[i] * (i - l + 1);
            while (cur >= k) {
                cur -= sum;
                cur -= ((long long)nums[l] * (i - l));
                sum -= nums[l];
                l++;
            }
            ans += (i - l + 1);
        }
        return ans;
    }
};