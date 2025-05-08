struct PR {
    int dis, x, y;
    bool operator<(const PR& a) const { return dis > a.dis; }
};
class Solution {
   public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        vis[0][0] = 1;
        vector<vector<int>> dis(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
        dis[0][0] = 0;
        priority_queue<PR> q;
        q.push({0, 0, 0});
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        while (!q.empty()) {
            PR t = q.top();
            q.pop();
            int x = t.x, y = t.y;
            if (x == n - 1 && y == m - 1)
                return t.dis;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                if (vis[xx][yy])
                    continue;
                vis[xx][yy] = 1;
                int t = (x + y) % 2 + 1;
                dis[xx][yy] = max(dis[x][y] + t, moveTime[xx][yy] + t);
                q.push({dis[xx][yy], xx, yy});
            }
        }
        return -1;
    }
};