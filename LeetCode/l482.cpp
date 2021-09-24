class Solution {
   public:
    string licenseKeyFormatting(string S, int K) {
        int c = 0, l = S.size();
        for (int i = 0; i < l; i++) {
            if (S[i] != '-')
                c++;
        }
        int w = c;
        c %= K;
        int p = 0, t = 0;
        string ans;
        if (c) {
            for (; p < l && ans.size() != c; p++) {
                if (S[p] != '-')

                {
                    if (S[p] <= 'z' && S[p] >= 'a')
                        S[p] += 'A' - 'a';
                    ans += S[p], t++;
                }
            }
            if (w != t)
                ans += '-';
        }
        for (int d = 0; p < l; p++) {
            if (S[p] != '-') {
                if (S[p] <= 'z' && S[p] >= 'a')
                    S[p] += 'A' - 'a';
                ans += S[p], t++;
                d++;
                if (d == K) {
                    d = 0;
                    if (t != w) {
                        ans += '-';
                    }
                }
            }
        }
        return ans;
    }
};