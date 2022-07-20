class Solution {
   public:
    int longestPalindrome(vector<string>& words) {
        int a[30][30] = {0};
        for (auto& i : words) {
            a[i[0] - 'a'][i[1] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                ans += min(a[i][j], a[j][i]) * 4;
            }
        }
        int f = 0;
        for (int i = 0; i < 26; i++) {
            ans += a[i][i] / 2 * 4;
            a[i][i] %= 2;
            if (a[i][i])
                f = 1;
        }
        return ans + f * 2;
    }
};