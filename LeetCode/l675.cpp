class Solution {
   public:
    int m, n;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int bfs(vector<vector<int>>& forest,
            int lastx,
            int lasty,
            int targetx,
            int targety) {
        vector<vector<bool>> visit(m, vector<bool>(n));
        visit[lastx][lasty] = 1;
        queue<pair<int, int>> q;
        q.emplace(lastx, lasty);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                if (x == targetx && y == targety)
                    return step;
                for (int k = 0; k < 4; ++k) {
                    int newx = dx[k] + x;
                    int newy = dy[k] + y;
                    if (newx >= 0 && newy >= 0 && newx < m && newy < n &&
                        !visit[newx][newy] && forest[newx][newy] != 0) {
                        visit[newx][newy] = 1;
                        q.emplace(newx, newy);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(), n = forest[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] == 0 || forest[i][j] == 1)
                    continue;
                v.emplace_back(make_pair(i, j));
            }
        }
        sort(v.begin(), v.end(),
             [&forest](pair<int, int> p1, pair<int, int> p2) {
                 return forest[p1.first][p1.second] <
                        forest[p2.first][p2.second];
             });
        int lastx = 0, lasty = 0, step = 0;
        for (auto [i, j] : v) {
            int dist = bfs(forest, lastx, lasty, i, j);
            if (dist == -1)
                return -1;
            step += dist;
            lastx = i;
            lasty = j;
        }
        return step;
    }
};
