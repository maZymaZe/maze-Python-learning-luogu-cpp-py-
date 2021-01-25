class Solution {
   public:
    int hs(int x, int y, int z) { return (x << 7) | (y << 2) | z; }
    int l, f[1 << 12], ans = 0,vis[1 << 12];
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    int regionsBySlashes(vector<string>& grid) {
        l = grid.size();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < 4; k++) {
                    f[hs(i, j, k)] = hs(i, j, k);
                }
            }
        }
        for (int i = 0; i < l; i++) {
            int p = 0;
            for (int j = 0; j < l; j++) {
                if (grid[i][p] == ' ') {
                    f[ff(hs(i, j, 0))] = f[ff(hs(i, j, 1))] =
                        f[ff(hs(i, j, 2))] = ff(hs(i, j, 3));
                } else if (grid[i][p] == '/') {
                    f[ff(hs(i, j, 0))] = ff(hs(i, j, 3));
                    f[ff(hs(i, j, 1))] = ff(hs(i, j, 2));
                } else {
                    f[ff(hs(i, j, 0))] = ff(hs(i, j, 1));
                    f[ff(hs(i, j, 2))] = ff(hs(i, j, 3));
                   
                }
                p++;
                if (i > 0) {
                    f[ff(hs(i, j, 0))] = ff(hs(i - 1, j, 2));
                }
                if (j > 0) {
                    f[ff(hs(i, j, 3))] = ff(hs(i, j - 1, 1));
                }
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                for (int k = 0; k < 4; k++) {
                    if (!vis[ff(hs(i, j, k))])
                        vis[ff(hs(i, j, k))]=1,
                        ans++;
                }
            }
        }
        return ans;
    }
};