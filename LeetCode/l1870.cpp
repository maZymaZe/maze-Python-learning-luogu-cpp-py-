class Solution {
   public:
    double cal(vector<int>& d, int x) {
        double ans = 0;
        double eps = 1e-10;
        int len = d.size();
        for (int i = 0; i < len; i++) {
            if (i != len - 1)
                ans += ceil((1.0 * d[i] / x) - eps);
            else
                ans += (1.0 * d[i] / x);
        }
        return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        double eps = 1e-10;
        if (dist.size() - 1 > hour - eps)
            return -1;
        int l = 0, r = 0x3f3f3f3f, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (cal(dist, mid) > hour + eps)
                l = mid;
            else
                r = mid;
        }
        return r;
    }
};