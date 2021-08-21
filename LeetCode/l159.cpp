class Solution {
   public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length(), c[400] = {0}, tt = 0, lf = 0, ans = 0;
        for (int i = 0; i < len; i++) {
            c[s[i]]++;
            if (c[s[i]] == 1)
                tt++;
            if (tt > 2) {
                while (tt > 2) {
                    c[s[lf]]--;
                    if (c[s[lf]] == 0)
                        tt--;
                    lf++;
                }
            }
            ans = max(ans, i - lf + 1);
        }
        return ans;
    }
};