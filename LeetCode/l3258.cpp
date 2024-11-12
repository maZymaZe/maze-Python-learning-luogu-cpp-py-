class Solution {
   public:
    int countKConstraintSubstrings(string s, int k) {
        int l = s.size(), c[2] = {0}, q = 0, ans = 0;
        for (int i = 0; i < l; i++) {
            c[s[i] - '0']++;
            while (c[0] > k && c[1] > k) {
                c[s[q] - '0']--;
                q++;
            }
            ans += i - q + 1;
        }
        return ans;
    }
};