class Solution {
   public:
    vector<string> printKMoves(int K) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
        int ux = 0, uy = 0, lx = 0, ly = 0, x = 0, y = 0, d = 0;
        set<pair<int, int>> s;
        for (int i = 0; i < K; i++) {
            if (s.count({x, y})) {
                s.erase({x, y});
                d = (d - 1 + 4) % 4;

            } else {
                s.insert({x, y});
                d = (d + 1) % 4;
            }
            x += dx[d], y += dy[d];
            ux = max(ux, x), lx = min(lx, x);
            uy = max(uy, y), ly = min(ly, y);
        }
        int xx = ux - lx + 1, yy = uy - ly + 1;
        vector<string> ans(yy, string(xx, '_'));
        for (const auto& i : s) {
            ans[yy - (i.second - ly) - 1][i.first - lx] = 'X';
        }
        char cc[6] = {'R', 'D', 'L', 'U'};
        ans[yy - (y - ly) - 1][x - lx] = cc[d];
        return ans;
    }
};