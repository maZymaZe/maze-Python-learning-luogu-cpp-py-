class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int v[20] = {0};
        for (int i = 0; i < 9; i++) {
            memset(v, 0, sizeof(v));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (v[board[i][j] - '0'])
                        return false;
                    v[board[i][j] - '0'] = 1;
                }
            }
            memset(v, 0, sizeof(v));
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (v[board[j][i] - '0'])
                        return false;
                    v[board[j][i] - '0'] = 1;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                memset(v, 0, sizeof(v));
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i * 3 + k][j * 3 + l] != '.') {
                            if (v[board[i * 3 + k][j * 3 + l] - '0'])
                                return false;
                            v[board[i * 3 + k][j * 3 + l] - '0'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};