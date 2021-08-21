class Solution {
   public:
    bool isOneEditDistance(string s, string t) {
        int ls = s.size(), lt = t.size();
        if (ls == lt) {
            int f = 0;
            for (int i = 0; i < ls; i++) {
                if (s[i] != t[i]) {
                    if (f)
                        return false;
                    else
                        f = 1;
                }
            }
            return f;
        }
        if (ls > lt)
            swap(s, t), swap(ls, lt);
        if (ls + 1 != lt)
            return false;
        if (ls == 0)
            return true;
        vector<int> v1(lt), v2(lt);
        for (int i = 0; i < ls; i++) {
            if (s[i] != t[i]) {
                break;
            } else
                v1[i] = 1;
        }
        for (int i = lt - 1; i > 0; i--) {
            if (t[i] != s[i - 1]) {
                break;
            } else
                v2[i] = 1;
        }
        if (v1[ls - 1] == 1)
            return true;
        if (v2[1] == 1)
            return true;
        for (int i = 1; i < lt - 1; i++) {
            if (v1[i - 1] && v2[i + 1])
                return true;
        }
        return false;
    }
};