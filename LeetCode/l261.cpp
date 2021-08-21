class Solution {
   public:
    vector<int> f;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]); }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size())
            return false;
        f.resize(n);
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (int i = 0; i < n - 1; i++) {
            f[ff(edges[i][0])] = ff(edges[i][1]);
        }
        int fff = ff(0);
        for (int i = 0; i < n; i++)
            if (ff(i) != fff)
                return false;
        return true;
    }
};