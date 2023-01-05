class Solution {
   public:
    static const int NMAX = (1 << 16);
    int c[NMAX] = {0}, p[NMAX] = {0};
    int qs(int l, int r) {
        if (l == 0)
            return p[r];
        return p[r] - p[l - 1];
    }
    int cal(int x) {
        int tot = 0;
        for (int i = 0; i < NMAX; i++) {
            if (!c[i])
                continue;
            int ps = 0, ct = 0;
            for (int j = 15; j >= 0; j--) {
                int ns = (i & (1 << j));
                int os = (ns ^ (1 << j));
                if (x & (1 << j)) {
                    ct += qs(ps | ns, (ps | ns) + (1 << j) - 1);
                    ps |= os;
                } else
                    ps |= ns;
            }

            ct += c[i ^ x];
            tot += c[i] * ct;
        }
        return tot / 2;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        for (auto i : nums) {
            c[i]++;
        }
        for (int i = 1; i < NMAX; i++) {
            p[i] = p[i - 1] + c[i];
        }
        return cal(high) - cal(low - 1);
    }
};