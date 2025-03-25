class Solution {
   public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto tl = grid, br = grid;

        for (int i = 0; i < m; i++) {
            int x = n - 1, y = i;
            unordered_set<int> s;
            while (x >= 0 && y >= 0) {
                br[x][y] = s.size();
                s.insert(grid[x][y]);
                x--, y--;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            int x = i, y = m - 1;
            unordered_set<int> s;
            while (x >= 0 && y >= 0) {
                br[x][y] = s.size();
                s.insert(grid[x][y]);
                x--, y--;
            }
        }
        for (int i = 0; i < n; i++) {
            int x = i, y = 0;
            unordered_set<int> s;
            while (x < n && y < m) {
                tl[x][y] = s.size();
                s.insert(grid[x][y]);
                x++, y++;
            }
        }
        for (int i = 1; i < m; i++) {
            int x = 0, y = i;
            unordered_set<int> s;
            while (x < n && y < m) {
                tl[x][y] = s.size();
                s.insert(grid[x][y]);
                x++, y++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tl[i][j] = abs(tl[i][j] - br[i][j]);
            }
        }
        return tl;
    }
};