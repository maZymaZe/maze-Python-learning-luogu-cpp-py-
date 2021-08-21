class Solution {
   public:
    bool canPermutePalindrome(string s) {
        int c[400] = {0}, cc = 0;
        for (auto i : s)
            c[i]++;
        for (int i = 0; i < 400; i++)
            cc += (c[i] & 1);
        return cc < 2;
    }
};