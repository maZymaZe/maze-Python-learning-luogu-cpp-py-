class Solution {
   public:
    bool check(const string& a, const string& b) {
        int la = a.size(), lb = b.size();
        if (la > lb)
            return false;
        for (int i = 0; i < la; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (string& x : words) {
            ans += check(x, s);
        }
        return ans;
    }
};