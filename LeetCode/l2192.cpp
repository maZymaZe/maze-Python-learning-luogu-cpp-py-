class Solution {
   public:
    vector<vector<int>> e;
    vector<vector<int>> ans;
    vector<int> vis;
    void f(int x, int y) {
        for (int nx : e[x]) {
            if (!vis[nx])
                vis[nx] = 1;
            else
                continue;
            f(nx, y);
            ans[y].push_back(nx);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        e.resize(n);
        ans.resize(n);
        vis.resize(n);

        for (const auto& edge : edges)
            e[edge[1]].push_back(edge[0]);
        for (int i = 0; i < n; i++) {
            fill(vis.begin(), vis.end(), 0);
            f(i, i);
        }
        for (auto& a : ans) {
            sort(a.begin(), a.end());
        }
        return ans;
    }
};