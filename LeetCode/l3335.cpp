class Solution {
   public:
    int lengthAfterTransformations(string s, int t) {
        int c[26][2] = {0}, MOD = 1e9 + 7;
        for (char ch : s) {
            c[ch - 'a'][0]++;
        }
        for (int i = 1; i <= t; i++) {
            int cur = (i & 1);
            c[0][cur] = c[25][!cur];
            for (int j = 1; j < 26; j++) {
                c[j][cur] = c[j - 1][!cur];
            }
            c[1][cur] += c[25][!cur];
            c[1][cur] %= MOD;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + c[i][t & 1]) % MOD;
        }
        return ans;
    }
};