class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1},
            dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if (board[nx][ny] == 1 || board[nx][ny] == 3) {
                                cnt++;
                            }
                        }
                    }
                    if (cnt == 3)
                        board[i][j] = 2;
                } else {
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                            if (board[nx][ny] == 1 || board[nx][ny] == 3) {
                                cnt++;
                            }
                        }
                    }
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 3;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 3)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};