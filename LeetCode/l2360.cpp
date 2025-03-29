class Solution {
   public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), p = 1, ans = -1;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            if (x[i] == 0) {
                int j = i, q = 1;
                while (j != -1 && x[j] == 0) {
                    x[j] = p, y[j] = q;
                    q++;
                    j = edges[j];
                }
                if (j != -1 && x[j] == p) {
                    ans = max(ans, q - y[j]);
                }
                p++;
            }
        }
        return ans;
    }
};