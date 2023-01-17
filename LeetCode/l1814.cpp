class Solution {
   public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums) {
            string x = to_string(i);
            reverse(x.begin(), x.end());
            int t = 0, l = x.size(), p = 0;
            while (t < l) {
                p = p * 10 + x[t] - '0';
                t++;
            }

            mp[i - p]++;
        }
        long long ans = 0, MOD = 1e9 + 7;
        for (auto it : mp) {
            ans += (long long)it.second * (it.second - 1) / 2;
            ans %= MOD;
        }
        return ans;
    }
};