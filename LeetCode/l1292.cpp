class Solution {
   public:
    int n, m;
    int ck(int x, vector<vector<int>>& ps, int y) {
        for (int i = x; i <= n; i++) {
            for (int j = x; j <= m; j++) {
                if (ps[i][j] - ps[i - x][j] - ps[i][j - x] + ps[i - x][j - x] <=
                    y)
                    return 1;
            }
        }
        return 0;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size(), m = mat[0].size();
        int mid, l = 0, r = min(n, m) + 1;
        vector<vector<int>> ps(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i + 1][j + 1] =
                    ps[i + 1][j] - ps[i][j] + ps[i][j + 1] + mat[i][j];
            }
        }
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (ck(mid, ps, threshold)) {
                l = mid;
            } else
                r = mid;
        }
        return l;
    }
};