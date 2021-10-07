class Solution {
   public:
    int strToInt(string s) {
        int l = s.size(), p = 0, f = 1, w = 0;
        while (!((s[p] >= '0' && s[p] <= '9') ||
                 ((s[p] == '-' || s[p] == '+') &&
                  (s[p + 1] >= '0' && s[p + 1] <= '9')))) {
            if (s[p] != ' ')
                return 0;
            p++;
        }
        if (s[p] == '+') {
            p++;
        } else if (s[p] == '-') {
            p++;
            f = -1;
        }
        long long ans = 0;
        for (int i = 1; i <= 12; i++) {
            if (s[p] >= '0' && s[p] <= '9') {
                if (w == 0 && s[p] == '0')
                    i--;
                else if (s[p] != '0')
                    w = 1;
                ans = ans * 10 + s[p] - '0';
                p++;
            } else
                break;
            if (p == l)
                break;
        }
        long long INF = 0x7FFFFFFF;
        if (f == 1 && ans > INF)
            ans = INF;
        else if (f == -1 && ans > INF + 1)
            ans = INF + 1;
        return ans * f;
    }
};