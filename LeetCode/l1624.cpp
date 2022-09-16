class Solution {
   public:
    int maxLengthBetweenEqualCharacters(string s) {
        int c[39] = {0};
        memset(c, -1, sizeof(c));
        int l = s.length(), ans = -1;
        for (int i = 0; i < l; i++) {
            if (c[s[i] - 'a'] == -1) {
                c[s[i] - 'a'] = i;
            } else {
                ans = max(ans, i - c[s[i] - 'a'] - 1);
            }
        }
        return ans;
    }
};