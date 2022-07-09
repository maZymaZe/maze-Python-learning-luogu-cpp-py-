class Solution {
   public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), mi = 0x3f3f3f3f, cnt = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < 0)
                    cnt++;
                mi = min(mi, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }
        if (cnt & 1)
            ans -= 2 * mi;
        return ans;
    }
};