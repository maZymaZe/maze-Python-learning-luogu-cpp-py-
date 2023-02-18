class Solution {
   public:
    int countHomogenous(string s) {
        long long res = 0;
        long long mod = 1e9 + 7;
        int prev = s[0];
        int cnt = 0;
        for (auto c : s) {
            if (c == prev) {
                cnt++;
            } else {
                res += (long long)(cnt + 1) * cnt / 2;
                cnt = 1;
                prev = c;
            }
        }
        res += (long long)(cnt + 1) * cnt / 2;
        return res % mod;
    }
};
