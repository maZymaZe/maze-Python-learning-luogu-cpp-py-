class Solution {
   public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            int t = 0;
            for (int j : grid[i])
                t += j;
            if (t == 0)
                return {i};
        }
        int sp[40] = {0}, lim = (1 << m);
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++) {
                x = x * 2 + grid[i][j];
            }
            if (sp[x] == 0)
                sp[x] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++) {
                x = x * 2 + grid[i][j];
            }
            for (int j = 0; j < lim; j++) {
                if ((j & x) == 0 && sp[j]) {
                    int a1 = sp[j] - 1, a2 = i;
                    if (a1 > a2)
                        swap(a1, a2);
                    return {a1, a2};
                }
            }
        }
        return {};
    }
};