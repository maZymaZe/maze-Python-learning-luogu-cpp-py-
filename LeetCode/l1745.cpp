class Solution {
   public:
    bool checkPartitioning(string s) {
        int l = s.size();
        vector<vector<int>> isp(l, vector<int>(l));
        for (int i = 0; i < l; i++) {
            for (int j = 1; j <= l; j++) {
                if (j == 1) {
                    isp[i][i] = 1;
                } else if (j == 2) {
                    if (i == l - 1)
                        break;
                    else
                        isp[i][i + 1] = (s[i] == s[i + 1]);
                } else {
                    int p = i + j / 2;
                    int q = i - j / 2 + 1 - j % 2;
                    if (p >= l || q < 0)
                        break;
                    isp[q][p] = (isp[q + 1][p - 1] && (s[p] == s[q]));
                }
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = i + 2; j < l; j++) {
                if (isp[0][i] && isp[i + 1][j - 1] && isp[j][l - 1])
                    return true;
            }
        }
        return false;
    }
};