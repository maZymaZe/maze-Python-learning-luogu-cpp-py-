class Solution {
   public:
    string maxValue(string n, int x) {
        int z = 1, l = n.length(), f = 0;
        string ans;
        for (int i = 0; i < l; i++) {
            if (i == 0 && n[0] == '-')
                z = 0, ans += n[0];
            else if (f)
                ans += n[i];
            else {
                if (z) {
                    if (n[i] - '0' < x) {
                        f = 1, ans += (char)(x + '0');
                    }
                } else {
                    if (n[i] - '0' > x) {
                        f = 1, ans += (char)(x + '0');
                    }
                }
                ans += n[i];
            }
        }
        if (!f)
            ans += (char)(x + '0');
        return ans;
    }
};