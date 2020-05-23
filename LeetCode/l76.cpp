int vis[300] = {0}, ck[300] = {0}, pc = 0, sti[300] = {0};
bool ok() {
    for (int i = 1; i <= pc; i++) {
        if (sti[i] < ck[i]) return false;
    }
    return true;
}
class Solution {
public:
    string minWindow(string s, string t) {
        memset(vis,0,sizeof(vis));
        memset(ck,0,sizeof(ck));
        memset(sti,0,sizeof(sti));
        pc=0;
        string ans;
        for (int i = 0; i < t.size(); i++) {
            if (!vis[t[i]]) {
                pc++;
                ck[pc]++;
                vis[t[i]] = pc;
            } else
                ck[vis[t[i]]]++;
        }
        int l = 0, r = 0;
        while (l < s.size()) {
            while (r <= s.size() && (!ok())) {
                sti[vis[s[r]]]++;
                r++;
            }
            if (r > s.size())
                break;
            else {
                while (l <= r && l < s.size() && ok()) {
                    sti[vis[s[l]]]--;
                    l++;
                }
                if (l > r || l > s.size())
                    break;
                else {
                    l--;
                    sti[vis[s[l]]]++;
                    if (ans.size() != 0 && r - l < ans.size()) {
                        ans = s.substr(l, r - l);
                    } else if (ans.size() == 0) {
                        ans = s.substr(l, r - l);
                    }
                }
            }
            sti[vis[s[l]]]--;
            l++;
        }
        return ans;
    }
};