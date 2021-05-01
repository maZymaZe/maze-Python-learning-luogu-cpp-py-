class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = s.size(), vis[300] = {0}, cnt = 0, tt = 0, ans = 0;
        for (int i = 0; i < l; i++) {
            if (!vis[s[i]])
                vis[s[i]]++, cnt++, ans = max(cnt, ans);
            else {
                while (s[tt] != s[i]) {
                    vis[s[tt]]--, cnt--, tt++;
                }
                tt++;
            }
        }
        return ans;
    }
};