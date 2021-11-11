int l, res[6];
vector<string> ans;
void dfs(int p1, int p2, int tot, bool flag, string& s) {
    if (p1 == l && p2 == 3 && tot < 256 && flag == false) {
        res[3] = tot;
        dfs(p1, p2 + 1, 0, true, s);
        return;
    }
    if (p1 == l && p2 == 4 && tot == 0 && flag) {
        string t1 = to_string(res[0]);
        for (int i = 1; i < 4; i++)
            t1 += "." + to_string(res[i]);
        ans.push_back(t1);
    } else if (p1 < l && p2 < 4 && tot < 256) {
        if (flag) {
            dfs(p1 + 1, p2, s[p1] - '0', false, s);
        } else {
            if (tot == 0) {
                res[p2] = 0;
                dfs(p1, p2 + 1, 0, true, s);
            } else {
                if (tot < 256) {
                    res[p2] = tot;
                    dfs(p1, p2 + 1, 0, true, s);
                }
                dfs(p1 + 1, p2, tot * 10 + s[p1] - '0', false, s);
            }
        }
    }
}
class Solution {
   public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        l = s.size();
        dfs(0, 0, 0, true, s);
        return ans;
    }
};