class Solution {
   public:
    vector<vector<int>> dist;
    int l, ans = 0;
    vector<int> diss;
    vector<int> vis;
    int minCostConnectPoints(vector<vector<int>>& points) {
        l = points.size();
        for (int i = 0; i < l; i++) {
            dist.push_back(vector<int>());
            for (int j = 0; j < l; j++) {
                dist[i].push_back(abs(points[i][0] - points[j][0]) +
                                  abs(points[i][1] - points[j][1]));
            }
        }
        diss = dist[0];
        vis.resize(l);
        vis[0] = 1;

        for (int i = 1; i < l; i++) {
            int mi = 0x3f3f3f3f, t = -1;
            for (int j = 0; j < l; j++) {
                if (!vis[j] && diss[j] < mi) {
                    mi = diss[j];
                    t = j;
                }
            }
            ans += diss[t];
            vis[t] = 1;
            for (int j = 0; j < l; j++) {
                if (!vis[j] && diss[j] > dist[t][j]) {
                    diss[j] = dist[t][j];
                }
            }
        }
        return ans;
    }
};