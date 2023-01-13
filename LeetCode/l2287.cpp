class Solution {
   public:
    int rearrangeCharacters(string s, string target) {
        int c1[26] = {0}, c2[26] = {0};
        for (auto i : s)
            c1[i - 'a']++;
        for (auto i : target)
            c2[i - 'a']++;
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 26; i++) {
            if (c2[i]) {
                ans = min(ans, c1[i] / c2[i]);
            }
        }
        return ans;
    }
};