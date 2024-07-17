class Solution {
   public:
    int lb(int x) { return (-x) & x; }
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> vroad(n, vector<int>(n, maxDistance + 10));
        for (const auto& r : roads) {
            vroad[r[0]][r[1]] = min(vroad[r[0]][r[1]], r[2]);
            vroad[r[1]][r[0]] = min(vroad[r[1]][r[0]], r[2]);
        }
        int ans = 1, lim = 1 << n;
        for (int pt = 1; pt < lim; pt++) {
            auto dis = vector<vector<int>>(n, vector<int>(n, maxDistance + 10));
            for (int i = 0; i < n; i++) {
                dis[i][i] = 0;
                for (int j = i + 1; j < n; j++) {
                    if (((1 << i) & pt) && ((1 << j) & pt)) {
                        dis[i][j] = vroad[i][j];
                        dis[j][i] = vroad[i][j];
                    }
                }
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (((1 << i) & pt) && ((1 << j) & pt) &&
                            ((1 << k) & pt)) {
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        }
                    }
                }
            }
            int ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (((1 << i) & pt) && ((1 << j) & pt)) {
                        if (dis[i][j] > maxDistance)
                            ok = 0;
                    }
                }
            }
            ans += ok;
        }
        return ans;
    }
};