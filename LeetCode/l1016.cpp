class Solution {
   public:
    bool queryString(string s, int n) {
        if (n > 1024)
            return 0;
        int l = s.size();
        int c[1024] = {0};
        for (int len = 1; len < 9; len++) {
            if (len > l)
                continue;
            int x = 0;
            for (int i = 0; i < len; i++) {
                x <<= 1;
                x |= (s[i] - '0');
            }
            c[x]++;
            for (int i = len; i < l; i++) {
                x ^= ((s[i - len] - '0') << (len - 1));
                x <<= 1;
                x |= (s[i] - '0');
                c[x]++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!c[i])
                return false;
        return true;
    }
};