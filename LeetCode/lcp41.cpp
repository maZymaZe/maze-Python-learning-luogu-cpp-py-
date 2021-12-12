class Solution {
   public:
    int flipChess(vector<string>& chessboard) {
        int ans = 0, n = chessboard.size(), m = chessboard[0].size();
        const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1},
                  dy[8] = {1, -1, 0, 1, -1, 1, -1, 0};
        auto ck = [&](int tx, int ty) {
            return tx >= 0 && ty >= 0 && tx < n && ty < m;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (chessboard[i][j] == '.') {
                    int c = 0;
                    auto np = chessboard;
                    queue<int> xx, yy;
                    xx.push(i), yy.push(j);
                    while (!xx.empty()) {
                        int x = xx.front(), y = yy.front();
                        xx.pop(), yy.pop();
                        for (int k = 0; k < 8; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            while (ck(nx, ny) && np[nx][ny] == 'O') {
                                nx = nx + dx[k];
                                ny = ny + dy[k];
                            }
                            if (ck(nx, ny) && np[nx][ny] == 'X') {
                                int px = x + dx[k], py = y + dy[k];
                                while (px != nx || py != ny) {
                                    if (np[px][py] == 'O') {
                                        np[px][py] = 'X';
                                        c++;
                                        xx.push(px), yy.push(py);
                                        px += dx[k], py += dy[k];
                                    }
                                }
                            }
                        }
                    }

                    ans = max(ans, c);
                }
            }
        }
        return ans;
    }
};