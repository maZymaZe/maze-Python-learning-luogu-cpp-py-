class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans = 0x3f3f3f3f, l = points.size(), p;
        for (int i = 0; i < l; i++) {
            if ((points[i][0] == x || points[i][1] == y) &&
                ans > abs(points[i][0] - x) + abs(points[i][1] - y)) {
                ans = abs(points[i][0] - x) + abs(points[i][1] - y);
                p = i;
            }
        }
        return ans == 0x3f3f3f3f ? -1 : p;
    }
};