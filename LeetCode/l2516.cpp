class Solution {
   public:
    int takeCharacters(string s, int k) {
        if (!k)
            return 0;
        int ok = 0, c[3] = {0}, p = 0, l = s.size();
        int q = l - 1;
        while (ok < 3 && p < l) {
            c[s[p] - 'a']++;
            if (c[s[p] - 'a'] == k)
                ok++;
            p++;
        }
        if (ok != 3)
            return -1;
        int ans = p;
        for (int i = p - 1; i >= 0; i--) {
            c[s[i] - 'a']--;
            if (c[s[i] - 'a'] == k - 1)
                ok--;
            if (ok < 3) {
                while (ok < 3) {
                    c[s[q] - 'a']++;
                    if (c[s[q] - 'a'] == k)
                        ok++;
                    q--;
                }
            }
            ans = min(ans, i + l - q - 1);
        }
        return ans;
    }
};