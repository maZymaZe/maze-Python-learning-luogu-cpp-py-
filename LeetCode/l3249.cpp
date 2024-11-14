class Solution {
   public:
    int ans;
    vector<vector<int>> e;
    int dfs(int x, int fa) {
        int c = -1, ok = 1, tot = 0;
        for (int i : e[x]) {
            if (i == fa)
                continue;
            if (c == -1) {
                c = dfs(i, x);
                tot += c;
            } else {
                int t = dfs(i, x);
                tot += t;
                if (c != t)
                    ok = 0;
            }
        }
        ans += ok;
        return tot + 1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        e.resize(n);
        for (const auto& v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        dfs(0, -1);
        return ans;
    }
};