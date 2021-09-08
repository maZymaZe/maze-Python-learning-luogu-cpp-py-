class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        queue<int> x, y, s;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    x.push(i), y.push(j), s.push(0), vis[i][j] = 1,
                                                     ans[i][j] = 0;
                }
            }
        }
        while (!x.empty()) {
            int tx = x.front(), ty = y.front(), ts = s.front();
            x.pop(), y.pop(), s.pop();
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i], ns = ts + 1;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                ans[nx][ny] = ns;
                x.push(nx), y.push(ny), s.push(ns);
            }
        }
        return ans;
    }
};
