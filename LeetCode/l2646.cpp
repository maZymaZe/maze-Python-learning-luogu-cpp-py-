class Solution {
   public:
    vector<vector<int>> e;
    vector<int> path, pz, cnt;
    int ans = 0;
    pair<int, int> ddfs(int cur, int fa) {
        int t1 = pz[cur] * cnt[cur] / 2, t2 = pz[cur] * cnt[cur];
        for (int i : e[cur]) {
            if (i != fa) {
                auto p = ddfs(i, cur);
                t1 += p.second;
                t2 += min(p.second, p.first);
            }
        }
        return {t1, t2};
    }
    void dfs(int cur, int fa, int dst) {
        path.push_back(cur);
        if (cur == dst) {
            for (int i : path) {
                cnt[i]++;
            }
            path.clear();
            return;
        } else {
            for (int i : e[cur]) {
                if (i != fa) {
                    dfs(i, cur, dst);
                }
            }
        }
        if (!path.empty())
            path.pop_back();
    }
    int minimumTotalPrice(int n,
                          vector<vector<int>>& edges,
                          vector<int>& price,
                          vector<vector<int>>& trips) {
        e.resize(n);
        cnt.resize(n);
        pz = price;
        for (auto v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        for (auto v : trips) {
            dfs(v[0], -1, v[1]);
        }
        auto p = ddfs(0, -1);
        return min(p.first, p.second);
    }
};