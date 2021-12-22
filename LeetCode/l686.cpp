class Solution {
   public:
    int repeatedStringMatch(string a, string b) {
        int la = a.size(), lb = b.size();
        int ml = max(2, lb / la + 3);
        string c;
        for (int i = 0; i < ml; i++)
            c += a;
        vector<int> nx(lb);
        nx[0] = -1;
        for (int i = 1; i < lb; i++) {
            int j = nx[i - 1];
            while (b[j + 1] != b[i] && j >= 0)
                j = nx[j];
            if (b[j + 1] == b[i])
                nx[i] = j + 1;
            else
                nx[i] = -1;
        }
        int pt = 0, lc = c.size(), pp = 0;
        while (pt < lc) {
            if (c[pt] == b[pp]) {
                pt++, pp++;
            } else if (pp == 0)
                pt++;
            else
                pp = nx[pp - 1] + 1;
            if (pp == lb) {
                return (pt - 1 + la) / la;
            }
        }
        return -1;
    }
};