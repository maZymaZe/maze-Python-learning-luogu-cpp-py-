struct pr {
    int l, r;
    bool operator<(const pr& x) const { return l < x.l; }
};
class Solution {
   public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pr> rg;
        for (int i = 0; i <= n; i++) {
            if (ranges[i]) {
                rg.push_back({i - ranges[i], i + ranges[i] - 1});
            }
        }
        sort(rg.begin(), rg.end());
        int ans = 0, mx = -1, p = 0, sz = rg.size();
        for (int i = 0; i < n; i++) {
            if (i <= mx)
                continue;
            int flag = 0;
            while (p < sz && rg[p].l <= i) {
                flag = 1;
                mx = max(mx, rg[p].r);
                p++;
            }
            if (!flag)
                return -1;
            ans++;
            if (i == n - 1 && mx < n - 1)
                return -1;
        }
        return ans;
    }
};