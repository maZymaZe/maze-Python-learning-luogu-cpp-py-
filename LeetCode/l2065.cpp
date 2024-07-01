class Solution {
   public:
    vector<int> vis, V;
    int tot, ans;
    vector<vector<pair<int, int>>> e;
    void dfs(int cur, int timeLeft) {
        if (cur == 0)
            ans = max(ans, tot);
        for (const auto& p : e[cur]) {
            if (timeLeft >= p.second) {
                vis[p.first]++;
                if (vis[p.first] == 1)
                    tot += V[p.first];
                dfs(p.first, timeLeft - p.second);
                vis[p.first]--;
                if (vis[p.first] == 0)
                    tot -= V[p.first];
            }
        }
    }
    int maximalPathQuality(vector<int>& values,
                           vector<vector<int>>& edges,
                           int maxTime) {
        int n = values.size(), l = edges.size();
        vis.resize(n);
        V = values;
        e.resize(n);
        for (const auto& ee : edges) {
            e[ee[0]].push_back({ee[1], ee[2]});
            e[ee[1]].push_back({ee[0], ee[2]});
        }
        tot = ans = V[0];
        vis[0] = 1;
        dfs(0, maxTime);
        return ans;
    }
};