class Solution {
   public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < m && i + j < n; j++) {
                v.push_back(mat[i + j][j]);
            }
            sort(v.begin(), v.end());
            int t = 0;
            for (int j = 0; j < m && i + j < n; j++) {
                mat[i + j][j] = v[t++];
            }
        }
        for (int i = 1; i < m; i++) {
            vector<int> v;
            for (int j = 0; j < n && i + j < m; j++) {
                v.push_back(mat[j][i + j]);
            }
            sort(v.begin(), v.end());
            int t = 0;
            for (int j = 0; j < n && i + j < m; j++) {
                mat[j][i + j] = v[t++];
            }
        }
        return mat;
    }
};