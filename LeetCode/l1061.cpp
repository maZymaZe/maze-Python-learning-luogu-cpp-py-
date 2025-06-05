class Solution {
   public:
    int f[27] = {0};
    int ff(int x) {
        if (f[x] == x)
            return x;
        return f[x] = ff(f[x]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 1; i <= 26; i++)
            f[i] = i;
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a' + 1;
            int b = s2[i] - 'a' + 1;
            int fa = ff(a);
            int fb = ff(b);
            if (fa != fb) {
                f[fa] = min(fa, fb);
                f[fb] = min(fa, fb);
            }
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            int a = baseStr[i] - 'a' + 1;
            ans += (char)(ff(a) + 'a' - 1);
        }
        return ans;
    }
};