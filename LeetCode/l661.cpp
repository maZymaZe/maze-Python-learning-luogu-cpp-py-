class Solution {
   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1},
            dy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int c = 0, tot = 0;
                for (int k = 0; k < 9; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        c++;
                        tot += img[nx][ny];
                    }
                }
                ans[i][j] = tot / c;
            }
        }
        return ans;
    }
};