class Solution {
   public:
    int minimumDistance(vector<vector<int>>& points) {
        int l = points.size();
        int mminp = 0, mmaxp = 0, mmin = 1e9 + 7, mmax = -1e9;
        int pminp = 0, pmaxp = 0, pmin = 1e9 + 7, pmax = -1e9;
        for (int i = 0; i < l; i++) {
            int m = points[i][0] - points[i][1];
            if (m > mmax) {
                mmax = m, mmaxp = i;
            }
            if (m < mmin) {
                mmin = m, mminp = i;
            }
            int p = points[i][0] + points[i][1];
            if (p > pmax) {
                pmax = p, pmaxp = i;
            }
            if (p < pmin) {
                pmin = p, pminp = i;
            }
        }
        int t1, t2;
        if (pmax - pmin > mmax - mmin) {
            t1 = pmaxp, t2 = pminp;
        } else {
            t1 = mminp, t2 = mmaxp;
        }
        int ans1, ans2;
        mminp = 0, mmaxp = 0, mmin = 1e9 + 7, mmax = -1e9;
        pminp = 0, pmaxp = 0, pmin = 1e9 + 7, pmax = -1e9;
        for (int i = 0; i < l; i++) {
            if (i == t1)
                continue;
            int m = points[i][0] - points[i][1];
            if (m > mmax) {
                mmax = m, mmaxp = i;
            }
            if (m < mmin) {
                mmin = m, mminp = i;
            }
            int p = points[i][0] + points[i][1];
            if (p > pmax) {
                pmax = p, pmaxp = i;
            }
            if (p < pmin) {
                pmin = p, pminp = i;
            }
        }
        ans1 = max(pmax - pmin, mmax - mmin);
        mminp = 0, mmaxp = 0, mmin = 1e9 + 7, mmax = -1e9;
        pminp = 0, pmaxp = 0, pmin = 1e9 + 7, pmax = -1e9;
        for (int i = 0; i < l; i++) {
            if (i == t2)
                continue;
            int m = points[i][0] - points[i][1];
            if (m > mmax) {
                mmax = m, mmaxp = i;
            }
            if (m < mmin) {
                mmin = m, mminp = i;
            }
            int p = points[i][0] + points[i][1];
            if (p > pmax) {
                pmax = p, pmaxp = i;
            }
            if (p < pmin) {
                pmin = p, pminp = i;
            }
        }
        ans2 = max(pmax - pmin, mmax - mmin);
        return min(ans1, ans2);
    }
};