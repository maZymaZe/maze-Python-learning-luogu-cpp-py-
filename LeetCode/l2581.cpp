class Solution {
   public:
    vector<vector<int>> e;
    unordered_set<long long> es;
    int n, kk, tot, ans;
    long long hs(int u, int v) { return (long long)u << 20 | v; }
    void dfs1(int cur, int fa) {
        for (int i : e[cur]) {
            if (i != fa) {
                if (es.count(hs(cur, i)))
                    tot++;
                dfs1(i, cur);
            }
        }
    }
    void dfs2(int cur, int fa) {
        if (tot >= kk)
            ans++;
        for (int i : e[cur]) {
            if (i != fa) {
                int delta = 0;
                if (es.count(hs(cur, i)))
                    delta--;
                if (es.count(hs(i, cur)))
                    delta++;
                tot += delta;
                dfs2(i, cur);
                tot -= delta;
            }
        }
    }
    int rootCount(vector<vector<int>>& edges,
                  vector<vector<int>>& guesses,
                  int k) {
        n = edges.size() + 1, kk = k, tot = 0, ans = 0;
        e.resize(n);
        for (const auto& eg : edges) {
            e[eg[0]].push_back(eg[1]);
            e[eg[1]].push_back(eg[0]);
        }
        for (const auto& g : guesses) {
            es.insert(hs(g[0], g[1]));
        }
        dfs1(0, -1);
        dfs2(0, -1);
        return ans;
    }
};