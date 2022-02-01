class Solution {
   public:
    bool ck(const string& x) {
        int l[26] = {0}, u[26] = {0};
        int len = x.size();
        for (int i = 0; i < len; i++) {
            if (x[i] >= 'a' && x[i] <= 'z')
                l[x[i] - 'a']++;
            else
                u[x[i] - 'A']++;
        }
        for (int i = 0; i < len; i++) {
            if (x[i] >= 'a' && x[i] <= 'z') {
                if (!u[x[i] - 'a'])
                    return false;
            } else if (!l[x[i] - 'A'])
                return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int l = s.size();
        for (int i = l; i > 0; i--) {
            for (int j = 0; j + i - 1 < l; j++) {
                if (ck(s.substr(j, i)))
                    return s.substr(j, i);
            }
        }
        return "";
    }
};