class Solution {
   public:
    int findPermutationDifference(string s, string t) {
        int a[26] = {0}, b[26] = {0};
        int l = s.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            a[s[i] - 'a'] = i;
            b[t[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++) {
            ans += abs(a[i] - b[i]);
        }
        return ans;
    }
};