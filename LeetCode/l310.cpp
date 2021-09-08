class Solution {
   public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> d(n);
        vector<vector<int>> nx(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            d[edges[i][0]]++, d[edges[i][1]]++;
            nx[edges[i][0]].push_back(edges[i][1]);
            nx[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> td, nn;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == 1)
                td.push_back(i), cnt++;
        }
        while (1) {
            nn.clear();
            if (cnt == n)
                return td;
            for (auto x : td) {
                d[x] = -1;
                for (auto y : nx[x]) {
                    d[y]--;
                    if (d[y] == 1)
                        nn.push_back(y), cnt++;
                }
            }
            td = nn;
        }
        return td;
    }
};