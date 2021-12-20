class Solution {
   public:
    bool canPermutePalindrome(string s) {
        int c[260] = {0}, d = 0;
        for (char x : s)
            c[x]++;
        for (int i = 0; i < 260; i++)
            if (c[i] & 1)
                d++;
        return d < 2;
    }
};