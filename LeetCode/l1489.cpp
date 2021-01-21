class Solution {
   public:
    vector<int> f;
    int l;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(
        int n,
        vector<vector<int>>& edges) {
        l = edges.size();
        for (int i = 0; i < l; i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });
        f.resize(n + 1);
        for (int i = 0; i <= n; i++)
            f[i] = i;
        int val = 0;
        for (int i = 0; i < l; i++) {
            int fx = ff(edges[i][0]), fy = ff(edges[i][1]);
            if (fx != fy)
                f[fx] = fy, val += edges[i][2];
        }
        vector<vector<int>> ans(2);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j <= n; j++)
                f[j] = j;
            int v = 0, cnt = 0;
            for (int j = 0; j < l; ++j) {
                if (i != j) {
                    int fx = ff(edges[j][0]), fy = ff(edges[j][1]);
                    if (fx != fy)
                        f[fx] = fy, v += edges[j][2], cnt++;
                }
            }
            if (cnt != n - 1 || (cnt == n - 1 && v > val)) {
                ans[0].push_back(edges[i][3]);
                continue;
            }
            for (int j = 0; j <= n; j++)
                f[j] = j;
            f[ff(edges[i][0])] = ff(edges[i][1]);
            cnt = 1, v = edges[i][2];
            for (int j = 0; j < l; j++) {
                if (i != j) {
                    int fx = ff(edges[j][0]), fy = ff(edges[j][1]);
                    if (fx != fy)
                        f[fx] = fy, v += edges[j][2], cnt++;
                }
            }
            if (v == val)
                ans[1].push_back(edges[i][3]);
        }
        return ans;
    }
};