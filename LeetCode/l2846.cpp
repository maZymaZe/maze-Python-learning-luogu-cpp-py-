struct PR {
    int to, val;
};
struct AR {
    int c[27] = {0};
};
AR operator+(const AR& a, const AR& b) {
    AR res;
    for (int i = 0; i < 27; i++) {
        res.c[i] = a.c[i] + b.c[i];
    }
    return res;
}
class Solution {
   public:
    vector<int> minOperationsQueries(int n,
                                     vector<vector<int>>& edges,
                                     vector<vector<int>>& queries) {
        vector<vector<PR>> nx(n);
        for (const auto& e : edges) {
            nx[e[0]].push_back({e[1], e[2]});
            nx[e[1]].push_back({e[0], e[2]});
        }
        vector<int> dep(n);
        vector<vector<int>> fa(n, vector<int>(16));
        vector<vector<AR>> ca(n, vector<AR>(16));
        function<void(int, int, int)> dfs = [&](int cur, int from, int d) {
            dep[cur] = d;
            for (auto i : nx[cur]) {
                if (i.to != from) {
                    fa[i.to][0] = cur;
                    ca[i.to][0].c[i.val]++;
                    dfs(i.to, cur, d + 1);
                }
            }
        };
        dfs(0, -1, 1);
        for (int i = 1; i < 16; i++) {
            for (int j = 1; j < n; j++) {
                fa[j][i] = fa[fa[j][i - 1]][i - 1];
                ca[j][i] = ca[j][i - 1] + ca[fa[j][i - 1]][i - 1];
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        unordered_map<int, int> mp;
        for (int i = 0; i < 16; i++)
            mp[(1 << i)] = i;
        for (int i = 0; i < m; i++) {
            AR tot;
            int u = queries[i][0], v = queries[i][1];
            int tu = u, tv = v;
            if (dep[tu] < dep[tv])
                swap(tu, tv);
            while (dep[tu] > dep[tv]) {
                int del = dep[tu] - dep[tv];
                int lo = mp[(del & (-del))];
                tot = tot + ca[tu][lo];
                tu = fa[tu][lo];
            }
            while (tv != tu) {
                int j;
                for (j = 0; j < 16; j++) {
                    if (fa[tu][j] == fa[tv][j]) {
                        break;
                    }
                }
                if (j == 0) {
                    tot = tot + ca[tu][j];
                    tu = fa[tu][j];
                    tot = tot + ca[tv][j];
                    tv = fa[tv][j];
                } else {
                    j--;
                    tot = tot + ca[tu][j];
                    tu = fa[tu][j];
                    tot = tot + ca[tv][j];
                    tv = fa[tv][j];
                }
            }
            int tg = dep[u] + dep[v] - dep[tu] * 2;
            int ta = tg;
            for (int j = 0; j < 27; j++)
                ta = min(ta, tg - tot.c[j]);
            ans[i] = ta;
        }
        return ans;
    }
};