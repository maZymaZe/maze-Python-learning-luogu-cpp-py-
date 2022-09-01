class Solution {
   public:
    bool ck(vector<vector<int>>& points, int a, int b, int c) {
        if (c == a || c == b)
            return true;
        int xa = points[a][0], ya = points[a][1], xb = points[b][0],
            yb = points[b][1], xc = points[c][0], yc = points[c][1];
        if (xa == xc && xb == xc)
            return true;
        if (xa == xc || xb == xc)
            return false;
        if (ya == yb && yb == yc)
            return true;
        if (ya == yc || yc == yb)
            return false;
        return (long long)(xc - xa) * (yc - yb) ==
               (long long)(xc - xb) * (yc - ya);
    }
    vector<int> bestLine(vector<vector<int>>& points) {
        int ans = 0, p, q, l = points.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int cnt = 0;
                for (int k = 0; k < l; k++) {
                    cnt += ck(points, i, j, k);
                }
                if (cnt > ans) {
                    ans = cnt, p = i, q = j;
                }
            }
        }
        return {p, q};
    }
};