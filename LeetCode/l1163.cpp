class Solution {
   public:
    string lastSubstring(string s) {
        int l = 0, r = 1, k = 0, n = s.size();
        while (r + k < n) {
            if (s[l + k] == s[r + k])
                k++;
            else if (s[l] < s[r + k]) {
                l = r + k;
                r = l + 1;
                k = 0;
            } else if (s[l + k] < s[r + k]) {
                l = r;
                r++;
                k = 0;
            } else {
                r++;
                k = 0;
            }
        }
        return s.substr(l);
    }
};
