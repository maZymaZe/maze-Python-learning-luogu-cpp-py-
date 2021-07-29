class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_set<int> l, c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    l.insert(i), c.insert(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (l.count(i) || c.count(j))
                    matrix[i][j] = 0;
            }
        }
    }
};