class Solution {
   public:
    int minDeletions(string s) {
        int c[26] = {0};
        for (char i : s)
            c[i - 'a']++;
        sort(c, c + 26);
        int ans = 0;
        for (int i = 26; i > 0; i--) {
            if (c[i] <= c[i - 1]) {
                ans += (c[i - 1] - max(0, c[i] - 1));
                c[i - 1] = max(0, c[i] - 1);
            }
        }
        return ans;
    }
};