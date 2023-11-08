class Solution {
   public:
    int findTheLongestBalancedSubstring(string s) {
        int l = s.size(), p = 0, ans = 0;
        while (p < l && s[p] == '1')
            p++;
        while (p < l) {
            int c0 = 0, c1 = 0;
            while (p < l && s[p] == '0')
                c0++, p++;
            while (p < l && s[p] == '1')
                c1++, p++;
            ans = max(ans, min(c0, c1));
        }
        return ans * 2;
    }
};