class Solution {
   private:
    using LL = long long;

   public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<vector<LL>> f(n + 1, vector<LL>(n + 1, LLONG_MAX / 2));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j != i) {
                    f[i][j] = min(f[i][j], (f[i - 1][j] + dist[i - 1] - 1) /
                                                   speed * speed +
                                               speed);
                }
                if (j != 0) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + dist[i - 1]);
                }
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[n][j] <= (LL)hoursBefore * speed) {
                return j;
            }
        }
        return -1;
    }
};
