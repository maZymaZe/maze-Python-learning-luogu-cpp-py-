class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        bool v[101][101] = {false};
        int d = 0, x = 0, y = 0, lx = matrix.size(), ly = matrix[0].size();
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

        ans.push_back(matrix[x][y]);
        v[x][y] = true;
        while (ans.size() < lx * ly) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < lx && nx >= 0 && ny < ly && ny >= 0 &&
                v[nx][ny] == false) {
                x = nx, y = ny;
                ans.push_back(matrix[x][y]);
                v[nx][ny] = true;
            } else
                d = (d + 1) % 4;
        }
        return ans;
    }
};