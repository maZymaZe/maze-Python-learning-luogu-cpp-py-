class Solution {
   public:
    int circleGame(vector<vector<int>>& toys,
                   vector<vector<int>>& circles,
                   int r) {
        sort(circles.begin(), circles.end());
        int ret = 0;
        for (auto i : toys) {
            int x = i[0], y = i[1], z = i[2];
            if (r < z)
                continue;
            auto it = lower_bound(circles.begin(), circles.end(),
                                  vector<int>{x - r + z, -1});
            auto eit = upper_bound(circles.begin(), circles.end(),
                                   vector<int>{x + r - z, INT_MAX});
            for (auto j = it; j != eit; ++j) {
                if ((long long)((*j)[0] - x) * ((*j)[0] - x) +
                        ((long long)((*j)[1] - y) * ((*j)[1] - y)) <=
                    (long long)(r - z) * (r - z)) {
                    ++ret;
                    break;
                }
            }
        }
        return ret;
    }
};