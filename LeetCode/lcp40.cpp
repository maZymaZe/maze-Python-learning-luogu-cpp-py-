class Solution {
   public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> o, e;
        for (int i : cards) {
            if (i & 1)
                o.push_back(i);
            else
                e.push_back(i);
        }
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        int lo = o.size(), le = e.size();
        if (le + (lo / 2 * 2) < cnt)
            return 0;
        int uo = min(lo / 2 * 2, cnt / 2 * 2);
        int ue = cnt - uo;
        if (ue > le || ue < 0)
            return 0;
        int tot = 0;

        for (int i = lo - uo; i < lo; i++) {
            tot += o[i];
        }
        for (int i = le - ue; i < le; i++) {
            tot += e[i];
        }
        int ans = tot;
        int p = le - ue - 1, q = lo - uo;
        while (q + 2 <= lo && p > 0) {
            tot -= o[q++];
            tot -= o[q++];
            tot += e[p--];
            tot += e[p--];
            ans = max(ans, tot);
        }
        return ans;
    }
};