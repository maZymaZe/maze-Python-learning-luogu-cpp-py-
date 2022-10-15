class Solution {
   public:
    const int MOD = 1e9 + 7;
    long long dp[27] = {0}, sum = 1;
    int distinctSubseqII(string s) {
        int l = s.size();
        dp[s[0] - 'a'] = 1;
        for (int i = 1; i < l; i++) {
            int j = s[i] - 'a';
            long long pre = dp[j];
            dp[j] = (sum + 1) % MOD;
            sum = (sum + dp[j] - pre + MOD) % MOD;
        }
        return sum;
    }
};