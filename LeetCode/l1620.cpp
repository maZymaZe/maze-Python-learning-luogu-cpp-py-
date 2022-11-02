class Solution {
   public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int ax = 0, ay = 0, p = 0;
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                int tot = 0;
                for (auto& v : towers) {
                    if (radius * radius >=
                        (i - v[0]) * (i - v[0]) + (j - v[1]) * (j - v[1])) {
                        tot += (int)(1.0 * v[2] /
                                     (sqrt((i - v[0]) * (i - v[0]) +
                                           (j - v[1]) * (j - v[1])) +
                                      1));
                    }
                }
                if (tot > p) {
                    p = tot;
                    ax = i, ay = j;
                }
            }
        }
        return {ax, ay};
    }
};