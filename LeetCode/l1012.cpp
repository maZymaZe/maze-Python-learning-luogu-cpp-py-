class Solution {
   public:
    int A(int x, int y) {
        int res = 1;
        for (int i = 0; i < x; i++) {
            res *= y--;
        }
        return res;
    }

    int f(int mask, const string& sn, int i, bool same) {
        if (i == sn.size()) {
            return 1;
        }
        int t = same ? sn[i] - '0' : 9, res = 0,
            c = __builtin_popcount(mask) + 1;
        for (int k = 0; k <= t; k++) {
            if (mask & (1 << k)) {
                continue;
            }
            if (same && k == t) {
                res += f(mask | (1 << t), sn, i + 1, true);
            } else if (mask == 0 && k == 0) {
                res += f(0, sn, i + 1, false);
            } else {
                res += A(sn.size() - 1 - i, 10 - c);
            }
        }
        return res;
    }

    int numDupDigitsAtMostN(int n) {
        string sn = to_string(n);
        return n + 1 - f(0, sn, 0, true);
    }
};
