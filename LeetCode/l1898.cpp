class Solution {
   public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int mid, ls = s.size(), lp = p.size(), l = 0, r = removable.size() + 1;
        vector<int> cr(ls);
        while (l + 1 < r) {
            mid = (l + r) / 2;
            int ok = 0;
            for (int i = 0; i < mid; i++) {
                cr[removable[i]] = 1;
            }
            int a = 0, b = 0;
            while (a < ls && b < lp) {
                if (cr[a])
                    a++;
                else {
                    if (s[a] == p[b])
                        b++;
                    a++;
                }
            }
            if (b == lp)
                ok = 1;
            for (int i = 0; i < mid; i++) {
                cr[removable[i]] = 0;
            }
            if (ok)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};