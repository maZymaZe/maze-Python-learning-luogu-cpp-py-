struct pt {
    int x, y, h;
    bool operator<(const pt& x) const { return h > x.h; }
};
class Solution {
   public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int res = 0, n = heightMap.size(), m = heightMap[0].size();
        if (n < 3 || m < 3)
            return 0;
        priority_queue<pt> q;
        vector<vector<int>> vis(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            q.push({i, 0, heightMap[i][0]});
            q.push({i, m - 1, heightMap[i][m - 1]});
            vis[i][0] = vis[i][m - 1] = 1;
        }
        for (int i = 0; i < m; i++) {
            q.push({0, i, heightMap[0][i]});
            q.push({n - 1, i, heightMap[n - 1][i]});
            vis[0][i] = vis[n - 1][i] = 1;
        }
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            pt tmp = q.top();

            int x = tmp.x, y = tmp.y, h = tmp.h;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
                    continue;
                if (heightMap[nx][ny] < h) {
                    res += h - heightMap[nx][ny];
                }
                vis[nx][ny] = 1;
                q.push({nx, ny, max(h, heightMap[nx][ny])});
            }
        }
        return res;
    }
};