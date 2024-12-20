class Solution {
   public:
    int minAnagramLength(string s) {
        int l = s.size();
        vector<vector<int>> c(26, vector<int>(l + 1));
        for (int i = 0; i < l; i++) {
            c[s[i] - 'a'][i + 1]++;
        }
        for (int i = 2; i <= l; i++) {
            for (int j = 0; j < 26; j++) {
                c[j][i] += c[j][i - 1];
            }
        }
        for (int i = 1; i <= l; i++) {
            if (l % i)
                continue;
            int g = l / i, ok = 1;
            for (int j = 0; j < 26; j++) {
                if (c[j][l] % g) {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                continue;
            for (int j = 0; j < 26; j++) {
                int st = c[j][l] / g;
                for (int k = i, x = st; k <= l; k += i, x += st) {
                    if (c[j][k] != x) {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                    break;
            }
            if (!ok)
                continue;
            return i;
        }
        return l;
    }
};