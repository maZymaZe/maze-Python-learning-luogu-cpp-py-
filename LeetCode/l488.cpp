class Solution {
   public:
    int ans = 0x3f3f3f3f;
    void dfs(const string& x, vector<int>& c, int stp) {
        if (stp >= ans)
            return;
        if (x.empty()) {
            ans = min(ans, stp);
            return;
        }
        int n = x.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            if (j + 1 < n && x[j + 1] == x[i])
                ++j;
            if (i == j && c[x[i] - 'A'] > 1) {
                string nx = x;
                string t = string(2, x[i]);
                nx.insert(nx.begin() + i, t.begin(), t.end());
                c[x[i] - 'A'] -= 2;
                dfs(cl(nx), c, stp + 2);
                c[x[i] - 'A'] += 2;
            } else if (j > i) {
                if (c[x[i] - 'A']) {
                    string nx = x;
                    nx.insert(nx.begin() + i, x[i]);
                    c[x[i] - 'A']--;
                    dfs(cl(nx), c, stp + 1);
                    c[x[i] - 'A']++;
                }
                for (char ch : {'R', 'Y', 'B', 'G', 'W'}) {
                    if (ch == x[i] || !c[ch - 'A'])
                        continue;
                    string nx = x;
                    nx.insert(nx.begin() + j, ch);
                    c[ch - 'A']--;
                    dfs(cl(nx), c, stp + 1);
                    c[ch - 'A']++;
                }
            }
        }
    }
    string cl(string& x) {
        if (x.size() < 3)
            return x;
        bool f = 1;
        while (f) {
            f = 0;
            for (int i = 0; i < x.size(); i++) {
                int j = i + 1;
                while (j < x.size() && x[j] == x[i])
                    ++j;
                if (j - i > 2) {
                    f = 1;
                    x.erase(x.begin() + i, x.begin() + j);
                }
            }
        }
        return x;
    }
    int findMinStep(string board, string hand) {
        vector<int> c(26);
        for (auto& x : hand)
            ++c[x - 'A'];
        dfs(board, c, 0);
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};