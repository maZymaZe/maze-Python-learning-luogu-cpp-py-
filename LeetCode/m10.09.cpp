class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while (x < n && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            if (matrix[x][y] > target) {
                y--;
            } else
                x++;
        }
        return false;
    }
};