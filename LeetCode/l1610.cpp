class Solution {
   public:
    int visiblePoints(vector<vector<int>>& points,
                      int angle,
                      vector<int>& location) {
        vector<double> angles;
        int l = points.size();
        int bs = 0, ans = 0, p = 0, q = 1;
        double pi = acos(-1.0), eps = 1e-6;
        double limit = 1.0 * angle / 180 * pi;
        for (int i = 0; i < l; i++) {
            if (points[i][0] == location[0] && points[i][1] == location[1]) {
                bs++;
            } else if (points[i][0] == location[0]) {
                if (points[i][1] > location[1])
                    angles.push_back(pi / 2);
                else
                    angles.push_back(-pi / 2);
            } else {
                int dx = points[i][0] - location[0],
                    dy = points[i][1] - location[1];
                if (dx > 0 && dy >= 0)
                    angles.push_back(atan(1.0 * dy / dx));
                else if (dx > 0 && dy < 0)
                    angles.push_back(atan(1.0 * dy / dx));
                else if (dx < 0 && dy < 0)
                    angles.push_back(atan(1.0 * dy / dx) - pi);
                else if (dx < 0 && dy >= 0)
                    angles.push_back(atan(1.0 * dy / dx) + pi);
            }
        }
        sort(angles.begin(), angles.end());
        int len = angles.size();
        if (len == 0)
            return bs;
        else
            ans = 1;
        while (p < len) {
            while (p != q &&
                   ((q > p ? angles[p] + limit + eps > angles[q]
                           : angles[p] + limit + eps > angles[q] + 2 * pi))) {
                q = (q + 1) % len;
            }
            if (q > p)
                ans = max(ans, q - p);
            else
                ans = max(ans, len - p + q);
            p++;
            if (p == q) {
                q = (q + 1) % len;
            }
        }
        return ans + bs;
    }
};