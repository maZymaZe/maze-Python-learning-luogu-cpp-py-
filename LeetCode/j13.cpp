class Solution {
   public:
    int movingCount(int m, int n, int k) {
        vector<vector<int> > vis(n, vector<int>(m));

        queue<int> qx, qy;
        int c = 0, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        qx.push(0), qy.push(0);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = 1, c++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                int t1 = nx, t2 = ny, tot = 0;
                while (t1)
                    tot += t1 % 10, t1 /= 10;
                while (t2)
                    tot += t2 % 10, t2 /= 10;
                if (tot > k)
                    continue;
                qx.push(nx), qy.push(ny);
            }
        }
        return c;
    }
};