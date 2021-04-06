class Solution {
   public:
    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {
        int c = 'a' - 1, l = words.size(), w = pattern.size();
        vector<int> mp(28), v(28);
        vector<string> ans;
        for (int i = 0; i < l; i++) {
            mp.clear();
            mp.resize(28);
            v.clear();
            v.resize(28);
            int f = 1;
            for (int j = 0; j < w; j++) {
                if (mp[words[i][j] - c]) {
                    if (mp[words[i][j] - c] != pattern[j] - c) {
                        f = 0;
                        break;
                    }
                } else {
                    mp[words[i][j] - c] = pattern[j] - c;
                }
            }
            for (int j = 1; j <= 26; j++) {
                if (mp[j]!=0&&v[mp[j]]) {
                    f = 0;
                    break;
                }
                v[mp[j]] = 1;
            }
            if (f) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};