class Solution {
   public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int l = points.size();
        double ma = 0;
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                for (int k = j + 1; k < l; k++) {
                    ma = max(ma, 1.0 / 2 *
                                    fabs(
                                            (points[j][0] - points[i][0]) *
                                            (points[k][1] - points[i][1]) -
                                            (points[k][0] - points[i][0]) *
                                            (points[j][1] - points[i][1])
                                        )
                            );
                }
            }
        }
        return ma;
    }
};