class Solution {
   public:
    vector<vector<int>> bicycleYard(vector<int>& position,
                                    vector<vector<int>>& terrain,
                                    vector<vector<int>>& obstacle) {
        int vis[102][102][102] = {0}, n = terrain.size(), m = terrain[0].size();
        queue<int> qx, qy, qv;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        qx.push(position[0]), qy.push(position[1]), qv.push(1);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), v = qv.front();
            qx.pop(), qy.pop(), qv.pop();
            if (vis[x][y][v])
                continue;
            vis[x][y][v] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int nv = v + terrain[x][y] - terrain[nx][ny] - obstacle[nx][ny];
                if (nv <= 0)
                    continue;
                qx.push(nx), qy.push(ny), qv.push(nv);
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j][1]) {
                    if (!(i == position[0] && j == position[1])) {
                        ans.push_back({i, j});
                    }
                }
            }
        }
        return ans;
    }
};