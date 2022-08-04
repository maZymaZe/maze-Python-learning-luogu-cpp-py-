class Solution {
   public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double ans[102][102] = {0};
        ans[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                if (ans[i][j] > 1) {
                    double t = (ans[i][j] - 1) / 2;
                    ans[i][j] = 1;
                    ans[i + 1][j] += t;
                    ans[i + 1][j + 1] += t;
                }
            }
        }
        return ans[query_row][query_glass];
    }
};