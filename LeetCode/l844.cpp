class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        int ls = S.size(), lt = T.size(), sc = 0, tc = 0;
        int ps = ls - 1, pt = lt - 1;
        while (ps >= 0 && pt >= 0) {
            while (ps >= 0 && S[ps] == '#') {
                ps--, sc++;
                while (ps >= 0 && sc) {
                    sc += (S[ps] == '#') ? 1 : -1;
                    ps--;
                }
            }
            while (pt >= 0 && T[pt] == '#') {
                pt--, tc++;

                while (pt >= 0 && tc) {
                    tc += (T[pt] == '#') ? 1 : -1;
                    pt--;
                }
            }
            if (pt >= 0 && ps >= 0) {
                if (T[pt] != S[ps])
                    return false;
                else pt--,ps--;
            }
            sc=0,tc=0;
        }
        if (pt >= 0) {
            while (pt >= 0 && T[pt] == '#') {
                pt--, tc++;

                while (pt >= 0 && tc) {
                    tc += (T[pt] == '#') ? 1 : -1;
                    pt--;
                }
            }
            if (pt >= 0)
                return false;
        }
        if (ps >= 0) {
            while (ps >= 0 && S[ps] == '#') {
                ps--, sc++;
                while (ps >= 0 && sc) {
                    sc += (S[ps] == '#') ? 1 : -1;
                    ps--;
                }
            }
            if (ps >= 0)
                return false;
        }
        return true;
    }
};