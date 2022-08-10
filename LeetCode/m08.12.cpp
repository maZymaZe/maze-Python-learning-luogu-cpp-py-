class Solution {
   public:
    vector<vector<string>> ans;
    vector<string> v;
    int mp[20][20], x[20], y[65], z[65], lim;
    char tp[20];
    void op() {
        v.clear();
        for (int i = 1; i <= lim; i++) {
            for (int j = 0; j < lim; j++) {
                tp[j] = mp[i][j + 1] ? 'Q' : '.';
            }
            v.push_back(string(tp));
        }
        ans.push_back(v);
    }
    void dfs(int n) {
        if (lim < n) {
            op();
            return;
        }
        for (int i = 1; i <= lim; i++) {
            if (!(x[i] || y[i + n] || z[i - n + 20])) {
                mp[n][i] = 1;
                x[i] = 1, y[i + n] = 1, z[i - n + 20] = 1;
                dfs(n + 1);
                mp[n][i] = 0;
                x[i] = 0, y[i + n] = 0, z[i - n + 20] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(mp, 0, sizeof(mp));
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(z, 0, sizeof(z));
        ans.clear();
        lim = n;
        dfs(1);
        return ans;
    }
};