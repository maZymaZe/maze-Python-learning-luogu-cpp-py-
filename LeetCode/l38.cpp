class Solution {
   public:
    string countAndSay(int n) {
        string s[2];
        s[1] = "1";
        for (int i = 2; i <= n; i++) {
            s[i & 1] = "";
            int op = ((i & 1) ^ 1);
            int l = s[op].size();
            int p = 0, q = 1;
            while (p < l && q <= l) {
                while (p < l && q < l && s[op][p] == s[op][q])
                    q++;

                s[i & 1] += to_string(q - p), s[i & 1] += s[op][p];
                p = q;
                q = p + 1;
            }
        }
        return s[n & 1];
    }
};