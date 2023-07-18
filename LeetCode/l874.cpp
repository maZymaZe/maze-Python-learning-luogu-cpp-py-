class Solution {
   public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (auto& obstacle : obstacles) {
            mp.emplace(obstacle[0] * 60001 + obstacle[1]);
        }
        int res = 0;
        for (int c : commands) {
            if (c < 0) {
                d += c == -1 ? 1 : -1;
                d %= 4;
                if (d < 0) {
                    d += 4;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    if (mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    res = max(res, px * px + py * py);
                }
            }
        }
        return res;
    }
};

