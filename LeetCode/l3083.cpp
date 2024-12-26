class Solution {
   public:
    bool isSubstringPresent(string s) {
        int v[256 * 256 + 10] = {0};
        int l = s.size();
        for (int i = 1; i < l; i++) {
            int x = s[i] * 256 + s[i - 1];
            int y = s[i - 1] * 256 + s[i];
            if (v[x] == 2)
                return true;
            v[x] = 1;
            if (v[y] == 1)
                return true;
            v[y] = 2;
        }
        return false;
    }
};