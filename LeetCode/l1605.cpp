class Solution {
   public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            ans[0][i] = colSum[i];
        int p = 0;
        for (int i = 1; i < n; i++) {
            while (rowSum[i] && ans[0][p] < rowSum[i]) {
                int t = ans[0][p];
                rowSum[i] -= t;
                ans[i][p] = t;
                ans[0][p] = 0;
                p++;
            }
            int t = rowSum[i];
            ans[0][p] -= t;
            ans[i][p] = t;
            if (!ans[0][p])
                p++;
        }
        return ans;
    }
};