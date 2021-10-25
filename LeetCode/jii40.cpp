class Solution {
   public:
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> lf(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (j == 0)
                        lf[i][j] = 1;
                    else
                        lf[i][j] = lf[i][j - 1] + 1;
                }
            }
        }
        int ret = 0;
        for (int j = 0; j < n; j++) {
            vector<int> u(m, 0), d(m, 0);
            stack<int> s;
            for (int i = 0; i < m; i++) {
                while (!s.empty() && lf[s.top()][j] >= lf[i][j]) {
                    s.pop();
                }
                u[i] = s.empty() ? -1 : s.top();
                s.push(i);
            }
            s = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!s.empty() && lf[s.top()][j] >= lf[i][j]) {
                    s.pop();
                }
                d[i] = s.empty() ? m : s.top();
                s.push(i);
            }
            for (int i = 0; i < m; i++) {
                int height = d[i] - u[i] - 1;
                int area = height * lf[i][j];
                ret = max(area, ret);
            }
        }
        return ret;
    }
};