class Solution {
   public:
    const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int n, m, l;
    string s;
    bool flag;
    void dfs(vector<vector<char>>& board,
             vector<vector<bool>>& vis,
             int x,
             int y,
             int nt) {
        if (flag)
            return;
        if (nt == l) {
            flag = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                board[nx][ny] == s[nt] && (!vis[nx][ny])) {
                vis[nx][ny] = true;
                dfs(board, vis, nx, ny, nt + 1);
                if (flag)
                    return;
                vis[nx][ny] = false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        flag = false;
        n = board.size();
        if (!n)
            return false;
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        s = word;
        l = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == s[0]) {
                    vis[i][j]=true;
                    dfs(board, vis, i, j, 1);
                    if(flag)return flag;
                    vis[i][j]=false;
                }
            }
        }
        return flag;
    }
};