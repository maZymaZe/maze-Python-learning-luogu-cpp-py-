class Solution {
   public:
    string longestWord(vector<string>& words) {
        int l = words.size(), ans = -1, MOD = 998244353;
        vector<int> whs(l);
        for (int i = 0; i < l; i++) {
            int len = words[i].length();
            for (int j = 0; j < len; j++) {
                whs[i] = ((long long)whs[i] * 31 + words[i][j]) % MOD;
            }
        }
        int mm[200] = {0};
        mm[0] = 1, mm[1] = 31;
        for (int i = 2; i < 102; i++) {
            mm[i] = (long long)mm[i - 1] * 31 % MOD;
        }
        for (int i = 0; i < l; i++) {
            int len = words[i].length();
            vector<int> v(len + 1), hh(len + 1);
            v[0] = 1;
            for (int j = 1; j <= len; j++) {
                hh[j] = ((long long)hh[j - 1] * 31 + words[i][j - 1]) % MOD;
                int suc = 0;
                for (int k = 0; k < l; k++) {
                    if (k == i || words[k].size() > j)
                        continue;
                    int kl = words[k].size();
                    if (((long long)mm[kl] * hh[j - kl] % MOD + whs[k]) % MOD ==
                            hh[j] &&
                        v[j - kl]) {
                        suc = 1;
                        break;
                    }
                }
                v[j] = suc;
            }
            if (v[len] == 1) {
                if (ans == -1)
                    ans = i;
                else if (words[i].size() > words[ans].size())
                    ans = i;
                else if (words[ans].size() == words[i].size() &&
                         words[i] < words[ans])
                    ans = i;
            }
        }
        if (ans == -1)
            return "";
        return words[ans];
    }
};