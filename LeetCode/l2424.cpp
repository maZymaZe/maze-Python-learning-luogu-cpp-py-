class Solution {
   public:
    int longestContinuousSubstring(string s) {
        int l = s.size(), cur = 1, mx = 1;
        for (int i = 1; i < l; i++) {
            if (s[i] == s[i - 1] + 1)
                cur++;
            else
                cur = 1;
            mx = max(mx, cur);
        }
        return mx;
    }
};