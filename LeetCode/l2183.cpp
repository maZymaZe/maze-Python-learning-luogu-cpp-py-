class Solution {
   public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[__gcd(x, k)]++;
        }
        long long ans = 0;
        for (auto [x1, y1] : mp) {
            for (auto [x2, y2] : mp) {
                if (1ll * x1 * x2 % k == 0) {
                    if (x1 == x2) {
                        ans += 1ll * y1 * (y1 - 1) / 2;
                    } else if (x1 < x2) {
                        ans += 1ll * y1 * y2;
                    }
                }
            }
        }
        return ans;
    }
};