class Solution {
   public:
    bool checkMove(vector<vector<char>>& board,
                   int rMove,
                   int cMove,
                   char color) {
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1},
            dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < 8; i++) {
            if (color == 'W') {
                int px = rMove + dx[i], py = cMove + dy[i];
                if (!(px >= 0 && px < n && py >= 0 && py < m &&
                      board[px][py] == 'B')) {
                    continue;
                }
                while (px >= 0 && px < n && py >= 0 && py < m) {
                    if (board[px][py] == 'B') {
                        px += dx[i];
                        py += dy[i];
                    } else if (board[px][py] == 'W') {
                        return true;
                    } else {
                        break;
                    }
                }
            }
            if (color == 'B') {
                int px = rMove + dx[i], py = cMove + dy[i];
                if (!(px >= 0 && px < n && py >= 0 && py < m &&
                      board[px][py] == 'W')) {
                    continue;
                }
                while (px >= 0 && px < n && py >= 0 && py < m) {
                    if (board[px][py] == 'W') {
                        px += dx[i];
                        py += dy[i];
                    } else if (board[px][py] == 'B') {
                        return true;
                    } else {
                        break;
                    }
                }
            }
        }
        return false;
    }
};