class Solution {
   public:
    bool cps(string& x, string& y) {
        if (x.size() == y.size()) {
            return x < y;
        }
        return x.size() > y.size();
    }
    bool ok(string& x, string& y) {
        int lx = x.size(), ly = y.size(), px = 0, py = 0;
        while (px < lx && py < ly) {
            if (x[px] == y[py])
                px++, py++;
            else
                py++;
            if (px == lx)
                return true;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans;
        for (auto i : dictionary) {
            if (ok(i, s)) {
                if (ans.size() == 0)
                    ans = i;
                else if (cps(i, ans))
                    ans = i;
            }
        }
        return ans;
    }
};