class Solution {
   public:
    int findSubstringInWraproundString(string p) {
        int n = p.size(), ans = 0, len = 1;
        vector<int> c(26);
        c[p[0] - 'a'] = 1;
        for (int i = 1; i < n; i++) {
            if (p[i] == p[i - 1] + 1 || (p[i] == 'a' && p[i - 1] == 'z'))
                len++;
            else
                len = 1;
            c[p[i] - 'a'] = max(c[p[i] - 'a'], len);
        }
        for (auto x : c)
            ans += x;
        return ans;
    }
};