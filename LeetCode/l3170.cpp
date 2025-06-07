class Solution {
   public:
    string clearStars(string s) {
        vector<vector<int>> pos(26);
        int l = s.size();
        vector<int> vis(l);
        for (int i = 0; i < l; i++) {
            if (s[i] == '*') {
                vis[i] = 1;
                for (int j = 0; j < 26; j++) {
                    if (!pos[j].empty()) {
                        int last = pos[j].back();
                        vis[last] = 1;
                        pos[j].pop_back();
                        break;
                    }
                }
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }
        string ans = "";
        for (int i = 0; i < l; i++) {
            if (!vis[i]) {
                ans += s[i];
            }
        }
        return ans;
    }
};