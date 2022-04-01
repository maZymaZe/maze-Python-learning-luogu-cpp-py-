class Solution {
   public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> v, vv;
        int MOD = 1e9 + 7;
        v.push_back(0);
        for (int i = 0; i < n; i++) {
            v.push_back(v.back() + nums[i]);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                vv.push_back(v[j] - v[i - 1]);
            }
        }
        sort(vv.begin(), vv.end());
        int ans = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            ans = (ans + vv[i]) % MOD;
        }
        return ans;
    }
};