class Solution {
   public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int nm = n * m;
        vector<int> px(nm + 1), py(nm + 1), vx(n + 1), vy(m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int t = mat[i][j];
                px[t] = i, py[t] = j;
            }
        }
        for (int i = 0; i < nm; i++) {
            vx[px[arr[i]]]++;
            vy[py[arr[i]]]++;
            if (vx[px[arr[i]]] == m || vy[py[arr[i]]] == n)
                return i;
        }
        return -1;
    }
};