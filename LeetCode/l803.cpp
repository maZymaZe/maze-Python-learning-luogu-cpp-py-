class Solution {
   public:
    vector<int> sz, f;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    void merge(int x, int y) {
        int u = ff(x), v = ff(y);
        if (u != v) {
            f[u] = v;
            sz[v] += sz[u];
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid,
                          vector<vector<int>>& hits) {
        int n = grid.size(), m = grid[0].size(), tot = n * m;
        sz.resize(tot + 1);
        f.resize(tot + 1);
        for (int i = 0; i <= tot; i++)
            f[i] = i, sz[i] = 1;
        vector<vector<int>> st = grid;
        for (int i = 0; i < hits.size(); i++) {
            st[hits[i][0]][hits[i][1]] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (st[i][j] == 1) {
                    if (i == 0) {
                        merge(n * m, i * m + j);
                    }
                    if (i > 0 && st[i - 1][j] == 1) {
                        merge(i * m + j, (i - 1) * m + j);
                    }
                    if (j > 0 && st[i][j - 1] == 1) {
                        merge(i * m + j, i * m + j - 1);
                    }
                }
            }
        }
        const vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> ret(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0)
                continue;

            int prev = sz[ff(n * m)];
            if (r == 0)
                merge(c, n * m);
            for (const auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (st[nr][nc] == 1) {
                        merge(r * m + c, nr * m + nc);
                    }
                }
            }
            int ss = sz[ff(n * m)];
            ret[i] = max(0, ss - prev - 1);
            st[r][c] = 1;
        }
        return ret;
    }
};