class Solution {
   public:
    string reverseStr(string s, int k) {
        int len = s.length();
        int l = 0, r = k;
        while (r <= len) {
            reverse(s.begin() + l, s.begin() + r);
            l += 2 * k;
            r += 2 * k;
        }
        reverse(s.begin() + l, s.end());
        return s;
    }
};