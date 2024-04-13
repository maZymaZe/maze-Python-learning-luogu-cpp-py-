class Solution {
   public:
    vector<int> f;
    int ff(int x) {
        if (f[x] == x)
            return x;
        return f[x] = ff(f[x]);
    }
    int findChampion(int n, vector<vector<int>>& edges) {
        f.resize(n);
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (const auto& e : edges) {
            f[e[1]] = ff(e[0]);
        }
        int ans = ff(0);
        for (int i = 1; i < n; i++) {
            if (ans != ff(i))
                return -1;
        }
        return ans;
    }
};