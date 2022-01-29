class Solution {
   public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        queue<int> x, y, z;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j])
                    x.push(i), y.push(j), z.push(0);
            }
        }
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        while (!x.empty()) {
            int tx = x.front(), ty = y.front(), tz = z.front();
            x.pop(), y.pop(), z.pop();
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    isWater[nx][ny] == 0) {
                    ans[nx][ny] = tz + 1;
                    isWater[nx][ny] = 1;
                    x.push(nx), y.push(ny), z.push(tz + 1);
                }
            }
        }
        return ans;
    }
};