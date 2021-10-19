class Solution {
   public:
    bool ck(const string& s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--) {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++, r--;
            } else
                return ck(s, l, r - 1) || ck(s, l + 1, r);
        }
        return true;
    }
};