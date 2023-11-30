class Solution {
   public:
    bool closeStrings(string word1, string word2) {
        int a[26] = {0}, b[26] = {0};
        for (char i : word1)
            a[i - 'a']++;
        for (char i : word2)
            b[i - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (a[i] == 0 && b[i] > 0)
                return false;
            if (b[i] == 0 && a[i] > 0)
                return false;
        }
        sort(a, a + 26), sort(b, b + 26);
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i])
                return false;
        return true;
    }
};