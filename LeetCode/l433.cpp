class Solution {
   public:
    int minMutation(string start, string end, vector<string>& bank) {
        int st = bank.size(), s = -1, t = -1;
        for (int i = 0; i < st; i++) {
            if (bank[i] == start) {
                s = i;
                break;
            }
        }
        if (s == -1)
            s = st, bank.push_back(start), st++;
        for (int i = 0; i < st; i++) {
            if (bank[i] == end) {
                t = i;
                break;
            }
        }
        if (t == -1)
            return -1;

        vector<vector<int>> ct(st);
        for (int i = 0; i < st; i++) {
            for (int j = i + 1; j < st; j++) {
                int dif = 0, l = bank[i].size();
                for (int k = 0; k < l; k++) {
                    if (bank[i][k] != bank[j][k])
                        dif++;
                }
                if (dif == 1) {
                    ct[i].push_back(j), ct[j].push_back(i);
                }
            }
        }
        vector<int> vis(st);
        queue<int> pos, ans;
        pos.push(s), ans.push(0);
        while (!pos.empty()) {
            int x = pos.front(), y = ans.front();
            pos.pop(), ans.pop();
            if (vis[x])
                continue;
            vis[x] = 1;
            for (auto i : ct[x]) {
                if (!vis[i]) {
                    pos.push(i), ans.push(y + 1);
                    if (i == t)
                        return y + 1;
                }
            }
        }
        return -1;
    }
};