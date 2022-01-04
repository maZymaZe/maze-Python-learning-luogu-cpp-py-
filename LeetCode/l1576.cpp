class Solution {
   public:
    string modifyString(string s) {
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == '?') {
                if ((i > 0 && s[i - 1] == 'a') ||
                    (i + 1 < l && s[i + 1] == 'a')) {
                    if ((i > 0 && s[i - 1] == 'b') ||
                        (i + 1 < l && s[i + 1] == 'b')) {
                        s[i] = 'c';
                    } else
                        s[i] = 'b';
                } else
                    s[i] = 'a';
            }
        }
        return s;
    }
};