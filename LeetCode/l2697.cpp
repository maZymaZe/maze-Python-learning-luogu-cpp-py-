class Solution {
   public:
    string makeSmallestPalindrome(string s) {
        int l = s.size();
        for (int i = 0, j = l - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                char m = min(s[i], s[j]);
                s[i] = s[j] = m;
            }
        }
        return s;
    }
};