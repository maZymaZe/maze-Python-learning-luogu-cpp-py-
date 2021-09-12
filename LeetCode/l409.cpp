class Solution {
   public:
    int longestPalindrome(string s) {
        int c[400] = {0}, ans = 0, f = 0;
        for (auto x : s)
            c[x]++;
        for (int i = 0; i < 400; i++) {
            if (c[i] & 1) {
                f = 1;
            }
            ans += (c[i] & 0xfffffffe);
        }
        return ans + f;
    }
};