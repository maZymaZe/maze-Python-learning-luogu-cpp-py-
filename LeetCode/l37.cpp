struct qs {
    int x, y;
};
int val[10][10] = {0};
class Solution {
   public:
    int mp[10][10] = {0};
    int hh[10][10] = {0}, ss[10][10] = {0}, bb[3][3][10] = {0}, cc = 0;
    int a[10] = {0}, b[10] = {0}, c[4][4] = {0}, flag = 0;
    static int cmp(const qs& a, const qs& b) {
        return val[a.x][a.y] > val[b.x][b.y];
    }
    qs ls[81];
    void dfs(int w, vector<vector<char>>& board) {
        if (w == cc + 1) {
            flag = 1;
            return;
        } else {
            for (int k = 9; k >= 1; k--) {
                if (hh[ls[w].x][k] == 0)
                    if (ss[ls[w].y][k] == 0)
                        if (bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k] == 0) {
                            mp[ls[w].x][ls[w].y] = k;
                            hh[ls[w].x][k]++;
                            ss[ls[w].y][k]++;
                            bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k]++;
                            dfs(w + 1, board);
                            if (flag)
                                return;
                            mp[ls[w].x][ls[w].y] = 0;
                            hh[ls[w].x][k]--;
                            ss[ls[w].y][k]--;
                            bb[(ls[w].x - 1) / 3][(ls[w].y - 1) / 3][k]--;
                        }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(val, 0, sizeof(val));
        cc = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                if (board[i - 1][j - 1] != '.') {
                    mp[i][j] = board[i - 1][j - 1] - '0';
                    if (hh[i][board[i - 1][j - 1] - '0'] == 0)
                        hh[i][board[i - 1][j - 1] - '0'] = 1, a[i]++;
                    if (ss[j][board[i - 1][j - 1] - '0'] == 0)
                        ss[j][board[i - 1][j - 1] - '0'] = 1, b[j]++;
                    if (bb[(i - 1) / 3][(j - 1) / 3]
                          [board[i - 1][j - 1] - '0'] == 0)
                        bb[(i - 1) / 3][(j - 1) / 3]
                          [board[i - 1][j - 1] - '0'] = 1,
                                                 c[(i - 1) / 3][(j - 1) / 3]++;
                } else {
                    cc++;
                    ls[cc].x = i;
                    ls[cc].y = j;
                }
            }
        }

        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                val[i][j] = max(c[(i - 1) / 3][(j - 1) / 3], max(a[i], b[j]));
            }
        }
        sort(ls + 1, ls + cc + 1, cmp);
        dfs(1, board);

        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                board[i - 1][j - 1] = mp[i][j] + '0';
            }
        }
    }
};