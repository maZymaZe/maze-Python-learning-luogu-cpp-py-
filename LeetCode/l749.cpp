class Solution {
   private:
    struct Area {
        unordered_set<int> dead;
        unordered_set<int> toDead;
        // 设置障碍的数量
        int cnt = 0;
    };

    // 数组的行数和列数
    int rows;
    int cols;
    bool** visited;

    // 遍历四个方向，写到一个数组里了
    int dires[5] = {0, 1, 0, -1, 0};

    // 基于深度优先的找没处理病毒区域（grid[x][y]==1）
    void dfs(const vector<vector<int>>& grid, Area& area, int x, int y) {
        if (grid[x][y] == 0) {
            ++area.cnt;
            area.toDead.insert(x * 50 + y);
        } else {
            // 其实这里只有1的情况，-1已经隔离的病毒在下面会过滤
            area.dead.insert(x * 50 + y);
            visited[x][y] = true;
            // 四个方向去查找1
            for (int k = 0; k < 4; ++k) {
                int nx = x + dires[k];
                int ny = y + dires[k + 1];
                // 有效范围； 没有遍历； 且没被隔离
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    !visited[nx][ny] && grid[nx][ny] != -1) {
                    dfs(grid, area, nx, ny);
                }
            }
        }
    }

   public:
    int containVirus(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int res = 0;

        // visisted来避免循环遍历
        visited = new bool*[rows];
        for (int i = 0; i < rows; ++i) {
            visited[i] = new bool[cols];
            memset(visited[i], 0, sizeof(bool) * cols);
        }

        while (true) {
            for (int i = 0; i < rows; ++i) {
                memset(visited[i], 0, sizeof(bool) * cols);
            }
            // 用一个简单数组记录最大值来模拟优先队列
            vector<Area> q;
            int maxIndex = 0;

            // 遍历每个点去dfs找区域
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    // 只有没遍历，而且为没隔离的病毒区域才考虑
                    if (!visited[i][j] && grid[i][j] == 1) {
                        Area area;
                        dfs(grid, area, i, j);
                        q.emplace_back(area);
                        if (area.toDead.size() > q[maxIndex].toDead.size()) {
                            maxIndex = q.size() - 1;
                        }
                    }
                }
            }

            // 所有病毒都处理完
            if (q.empty()) {
                break;
            }

            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto& a = q[i];
                if (i != maxIndex) {
                    for (const int& p : a.toDead) {
                        grid[p / 50][p % 50] = 1;
                    }
                } else {
                    for (const int& p : a.dead) {
                        grid[p / 50][p % 50] = -1;
                    }
                    res += a.cnt;
                }
            }
        }

        return res;
    }
};
