class Solution {
   public:
    int countVowelPermutation(int n) {
        long long c[2][5] = {0}, MOD = 1e9 + 7, ans = 0;
        c[1][0] = c[1][1] = c[1][2] = c[1][3] = c[1][4] = 1;
        for (int i = 2; i <= n; i++) {
            int w = (i & 1);
            c[w][0] = (c[!w][1] + c[!w][2] + c[!w][4]) % MOD;
            c[w][1] = (c[!w][0] + c[!w][2]) % MOD;
            c[w][2] = (c[!w][1] + c[!w][3]) % MOD;
            c[w][3] = (c[!w][2]) % MOD;
            c[w][4] = (c[!w][2] + c[!w][3]) % MOD;
        }
        for (int i = 0; i < 5; i++)
            ans += c[n & 1][i];
        ans %= MOD;
        return ans;
    }
};