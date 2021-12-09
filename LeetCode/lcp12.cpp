class Solution {
   public:
    bool ck(vector<int>& time, int T, int m) {
        int ttot = T + 2, tma = 0, d = 0, l = time.size();
        for (int i = 0; i < l; i++) {
            tma = max(tma, time[i]);
            if (ttot - tma + time[i] > T)
                d++, ttot = 0, tma = 0;
            if (d > m)
                return false;
            ttot += time[i];
            tma = max(tma, time[i]);
        }
        return true;
    }
    int minTime(vector<int>& time, int m) {
        int l = 0, r = 1e9 + 7, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (ck(time, mid, m)) {
                r = mid;
            } else
                l = mid + 1;
        }
        return r;
    }
};