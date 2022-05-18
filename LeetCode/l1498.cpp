class Solution {
   public:
    long long MOD = 1e9 + 7;
    long long qpow(long long a, long long b) {
        long long ret = 1;
        while (b) {
            if (b & 1)
                ret = ret * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ret;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            if (2 * nums[i] > target)
                break;
            int cnt = upper_bound(nums.begin(), nums.end(), target - nums[i]) -
                      nums.begin() - i - 1;
            ans += qpow(2, cnt);
            ans %= MOD;
        }
        return ans;
    }
};