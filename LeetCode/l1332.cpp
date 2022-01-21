class Solution {
   public:
    int removePalindromeSub(string s) {
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] != s[l - i - 1])
                return 2;
        }
        return 1;
    }
};