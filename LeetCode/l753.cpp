class Solution {
   public:
    unordered_set<int> s;
    string ans;
    int hg, kk;
    void dfs(int x) {
        for (int i = 0; i < kk; i++) {
            int nei = x * 10 + i;
            if (!s.count(nei)) {
                s.insert(nei);
                dfs(nei % hg);
                ans += (i + '0');
            }
        }
    }
    string crackSafe(int n, int k) {
        hg = pow(10, n - 1);
        kk = k;
        dfs(0);
        ans += string(n - 1, '0');
        return ans;
    }
};