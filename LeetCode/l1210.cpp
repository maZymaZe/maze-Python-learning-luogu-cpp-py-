struct tp {
    int x, y, z;
};
class Solution {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int v[102][102][2] = {0};
        v[0][1][0] = 1;
        queue<tp> q;
        q.push({0, 1, 0});
        while (!q.empty()) {
            tp h = q.front();
            int w = v[h.x][h.y][h.z];
            q.pop();
            if (h.z == 0) {
                if (h.y + 1 < n && !grid[h.x][h.y + 1] && !v[h.x][h.y + 1][0]) {
                    v[h.x][h.y + 1][0] = w + 1;
                    q.push({h.x, h.y + 1, 0});
                }
                if (h.x + 1 < n && !grid[h.x + 1][h.y] &&
                    !grid[h.x + 1][h.y - 1] && !v[h.x + 1][h.y][0]) {
                    v[h.x + 1][h.y][0] = w + 1;
                    q.push({h.x + 1, h.y, 0});
                }
                if (h.x + 1 < n && !grid[h.x + 1][h.y] &&
                    !grid[h.x + 1][h.y - 1] && !v[h.x + 1][h.y - 1][1]) {
                    v[h.x + 1][h.y - 1][1] = w + 1;
                    q.push({h.x + 1, h.y - 1, 1});
                }
            } else {
                if (h.y + 1 < n && !grid[h.x][h.y + 1] &&
                    !grid[h.x - 1][h.y + 1] && !v[h.x][h.y + 1][1]) {
                    v[h.x][h.y + 1][1] = w + 1;
                    q.push({h.x, h.y + 1, 1});
                }
                if (h.x + 1 < n && !grid[h.x + 1][h.y] && !v[h.x + 1][h.y][1]) {
                    v[h.x + 1][h.y][1] = w + 1;
                    q.push({h.x + 1, h.y, 1});
                }
                if (h.y + 1 < n && !grid[h.x][h.y + 1] &&
                    !grid[h.x - 1][h.y + 1] && !v[h.x - 1][h.y + 1][0]) {
                    v[h.x - 1][h.y + 1][0] = w + 1;
                    q.push({h.x - 1, h.y + 1, 0});
                }
            }
        }
        return v[n - 1][n - 1][0] - 1;
    }
};