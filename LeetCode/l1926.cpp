class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        queue<int> qx, qy, qz;
        qx.push(entrance[0]), qy.push(entrance[1]), qz.push(0);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), z = qz.front();
            qx.pop(), qy.pop(), qz.pop();
            maze[x][y] = '+';
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    if (z == 0)
                        continue;
                    return z;
                } else {
                    if (maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        qx.push(nx), qy.push(ny), qz.push(z + 1);
                    }
                }
            }
        }
        return -1;
    }
};