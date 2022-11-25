class Solution {
   public:
    bool ck(string& s, string& t) {
        int ls = s.size(), lt = t.size(), ps = 0, pt = 0;
        while (ps < ls && pt < lt) {
            int cs = 1, ct = 1;
            if (s[ps] != t[pt])
                return false;
            while (ps + 1 < ls && s[ps] == s[ps + 1]) {
                ps++, cs++;
            }
            while (pt + 1 < lt && t[pt] == t[pt + 1]) {
                pt++, ct++;
            }
            if (ct > cs || (ct == 1 && cs == 2))
                return false;
            pt++;
            ps++;
        }
        return pt == lt && ps == ls;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto& it : words) {
            ans += ck(s, it);
        }
        return ans;
    }
};