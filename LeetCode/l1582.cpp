class Solution {
   public:
    int numSpecial(vector<vector<int>>& mat) {
        int l = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> r(l), c(n);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < n; j++) {
                ans += (r[i] == 1 && c[j] == 1 && mat[i][j] == 1);
            }
        }
        return ans;
    }
};