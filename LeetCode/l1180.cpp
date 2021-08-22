class Solution {
   public:
    int countLetters(string s) {
        int ma[26] = {0}, c[26] = {0}, p = -1;
        int ans = 0;
        for (auto cc : s) {
            if (cc == p) {
                c[cc - 'a']++;
                ans += c[cc - 'a'];
            } else {
                c[cc - 'a'] = 1;
                ans += c[cc - 'a'];
            }
            p = cc;
        }

        return ans;
    }
};