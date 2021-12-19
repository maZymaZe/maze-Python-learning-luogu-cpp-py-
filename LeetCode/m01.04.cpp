class Solution {
   public:
    bool canPermutePalindrome(string s) {
        int c[26] = {0}, d = 0;
        for (char x : s)
            c[x - 'a']++;
        for (int i = 0; i < 26; i++)
            if (c[i] & 1)
                d++;
        return d < 2;
    }
};