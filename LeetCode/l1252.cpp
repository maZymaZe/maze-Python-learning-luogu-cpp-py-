class Solution {
   public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int x[60] = {0}, y[60] = {0};
        int l = indices.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            x[indices[i][0]] ^= 1;
            y[indices[i][1]] ^= 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += (x[i] ^ y[j]);
            }
        }
        return ans;
    }
};