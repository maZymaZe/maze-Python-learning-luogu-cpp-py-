class Solution {
   public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> a, b;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) {
                    a.push_back({i, j});
                } else {
                    for (int k = 1; k < grid[i][j]; k++) {
                        b.push_back({i, j});
                    }
                }
            }
        }
        sort(a.begin(), a.end());
        int l = a.size();
        int ans = 100000000;
        do {
            int cnt = 0;
            for (int i = 0; i < l; i++) {
                cnt += abs(a[i].first - b[i].first) +
                       abs(a[i].second - b[i].second);
            }
            ans = min(ans, cnt);
        } while (next_permutation(a.begin(), a.end()));
        return ans;
    }
};