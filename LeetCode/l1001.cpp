class Solution {
   public:
    vector<int> gridIllumination(int n,
                                 vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        set<pair<int, int>> s;
        map<int, int> x, y, z, w;
        for (const auto& i : lamps)
            s.insert({i[0], i[1]});
        for (const auto& i : s) {
            int p = i.first, q = i.second;
            x[p]++, y[q]++, z[p + q]++, w[p - q]++;
        }
        int l = queries.size();
        vector<int> ans(l);
        int dx[9] = {1, 1, 1, 0, 0, -1, -1, -1, 0},
            dy[9] = {1, 0, -1, 1, -1, 1, 0, -1, 0};
        for (int i = 0; i < l; i++) {
            int p = queries[i][0], q = queries[i][1];
            if (x[p] > 0 || y[q] > 0 || z[p + q] > 0 || w[p - q] > 0) {
                ans[i] = 1;
            } else
                ans[i] = 0;
            for (int j = 0; j < 9; j++) {
                int np = p + dx[j], nq = q + dy[j];
                if (s.count({np, nq})) {
                    s.erase({np, nq});
                    x[np]--;
                    y[nq]--;
                    z[np + nq]--;
                    w[np - nq]--;
                }
            }
        }
        return ans;
    }
};