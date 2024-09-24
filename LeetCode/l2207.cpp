class Solution {
   public:
    long long maximumSubsequenceCount(string text, string pattern) {
        string s[2] = {pattern[0] + text, text + pattern[1]};
        long long ans[2] = {0};
        for (int i = 0; i < 2; i++) {
            int l = s[i].size();
            vector<int> cnt(l);
            cnt[l - 1] = (s[i][l - 1] == pattern[1]);
            for (int j = l - 2; j >= 0; j--) {
                cnt[j] = cnt[j + 1] + (pattern[1] == s[i][j]);
            }
            for (int j = 0; j < l - 1; j++) {
                if (s[i][j] == pattern[0])
                    ans[i] += cnt[j + 1];
            }
        }
        return max(ans[0], ans[1]);
    }
};