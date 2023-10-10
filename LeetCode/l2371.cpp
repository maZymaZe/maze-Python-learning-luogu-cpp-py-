class Solution {
   public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> nn;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            nn.push_back((long long)nums[i] + (s[i] == 'L' ? -1 : 1) * d);
        }
        sort(nn.begin(), nn.end());
        long long ans = 0, MOD = 1e9 + 7;
        for (int i = 1; i < l; i++) {
            ans += (nn[i] - nn[i - 1]) * (i) % MOD * (l - i) % MOD;
            ans %= MOD;
        }
        return ans;
    }
};