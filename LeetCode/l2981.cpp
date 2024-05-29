class Solution {
   public:
    int maximumLength(string s) {
        int c1[26], c2[26];
        int l = s.size();
        for (int i = l - 2; i >= 1; i--) {
            memset(c1, 0, sizeof(c1));
            memset(c2, 0, sizeof(c2));
            int tp = 0;
            for (int j = 0; j < i; j++) {
                c1[s[j] - 'a']++;
                if (c1[s[j] - 'a'] == 1)
                    tp++;
            }
            if (tp == 1)
                c2[s[i - 1] - 'a']++;
            for (int j = i; j < l; j++) {
                c1[s[j] - 'a']++;
                if (c1[s[j] - 'a'] == 1)
                    tp++;
                c1[s[j - i] - 'a']--;
                if (c1[s[j - i] - 'a'] == 0)
                    tp--;
                if (tp == 1) {
                    c2[s[j] - 'a']++;
                    if (c2[s[j] - 'a'] == 3)
                        return i;
                }
            }
        }
        return -1;
    }
};