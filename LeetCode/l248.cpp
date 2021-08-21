class Solution {
   public:
    string s[4] = {"", "0", "1", "8"}, l[5] = {"0", "1", "8", "6", "9"},
           r[5] = {"0", "1", "8", "9", "6"};
    int ans = 0;
    void dfs(string x, string& low, string& high) {
        if (low.length() <= x.size() && x.size() <= high.size()) {
            if (x.size() == high.size() && x > high)
                return;
            if (x.size() == low.size() && x >= low || x.size() > low.size()) {
                if (x.size() == 1 || x[0] != '0')
                    ans++;
            }
        }
        if (x.size() + 2 <= high.size()) {
            for (int i = 0; i < 5; i++) {
                dfs(l[i] + x + r[i], low, high);
            }
        }
    }
    int strobogrammaticInRange(string low, string high) {
        for (auto i : s)
            dfs(i, low, high);
        return ans;
    }
};