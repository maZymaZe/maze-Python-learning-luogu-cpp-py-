class Solution {
   public:
    vector<int> f, c;
    int ff(int x) {
        if (f[x] == x)
            return x;
        return f[x] = ff(f[x]);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        f.resize(n), c.resize(n);
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (const auto& e : edges) {
            f[ff(e[0])] = ff(e[1]);
        }
        long long ans = (long long)n * (n - 1) / 2;
        for (int i = 0; i < n; i++) {
            int x = ff(i);
            ans -= c[x];
            c[x]++;
        }
        return ans;
    }
};