class Solution {
   public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), INF = 0x3f3f3f3f;
        vector<vector<int>> fm(n, vector<int>(m, INF));
        queue<int> fx, fy;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fx.push(i), fy.push(j);
                    fm[i][j] = 0;
                }
            }
        }
        while (!fx.empty()) {
            int tx = fx.front(), ty = fy.front();
            fx.pop();
            fy.pop();
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    fm[nx][ny] == INF && grid[nx][ny] == 0) {
                    fx.push(nx);
                    fy.push(ny);
                    fm[nx][ny] = fm[tx][ty] + 1;
                }
            }
        }

        auto check = [&](int bt) {
            vector<vector<int>> vt(n, vector<int>(m, -1));
            vt[0][0] = bt;
            queue<int> qx, qy;
            qx.push(0), qy.push(0);
            while (!qx.empty()) {
                int tx = qx.front(), ty = qy.front();
                int tz = vt[tx][ty];
                qx.pop();
                qy.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = tx + dx[i], ny = ty + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        if (nx == n - 1 && ny == m - 1) {
                            if (tz + 1 <= fm[nx][ny]) {
                                return true;
                            } else {
                                return false;
                            }
                        } else {
                            if (grid[nx][ny] == 0 && vt[nx][ny] == -1 &&
                                tz + 1 < fm[nx][ny]) {
                                vt[nx][ny] = tz + 1;
                                qx.push(nx), qy.push(ny);
                            }
                        }
                    }
                }
            }
            return false;
        };

        if (!check(0))
            return -1;
        int l = 0, r = 1000000000;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};