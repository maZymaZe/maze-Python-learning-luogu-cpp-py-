class Solution {
   public:
    int alternateDigitSum(int n) {
        int ans = 0;
        string s = to_string(n);
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (i & 1) {
                ans -= s[i] - '0';
            } else {
                ans += s[i] - '0';
            }
        }
        return ans;
    }
};