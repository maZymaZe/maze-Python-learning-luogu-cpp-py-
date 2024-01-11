class Solution {
   public:
    int addMinimum(string word) {
        int l = word.size(), ans = 0, s = 0, p = 0;
        while (p < l || s != 0) {
            if (p < l && word[p] - 'a' == s) {
                p++;
                s = (s + 1) % 3;
            } else {
                ans++;
                s = (s + 1) % 3;
            }
        }
        return ans;
    }
};