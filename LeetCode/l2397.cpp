class Solution {
   public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size(), m = matrix[0].size();
        int lm = (1 << m), ans = 0;
        for (int i = 0; i < lm; i++) {
            int c = 0, tot = 0;
            for (int j = 0; j < m; j++) {
                c += (!!(i & (1 << j)));
            }
            if (c != numSelect)
                continue;
            for (int j = 0; j < n; j++) {
                int flag = 1;
                for (int k = 0; k < m; k++) {
                    if (matrix[j][k] && !(i & (1 << k))) {
                        flag = 0;
                        break;
                    }
                }
                tot += flag;
            }
            ans = max(tot, ans);
        }
        return ans;
    }
};