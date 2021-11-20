class Solution {
   public:
    int f[1001] = {0};
    int ff(int x) {
        if (f[x] == x)
            return x;
        else
            return f[x] = ff(f[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int l = edges.size();
        for (int i = 1; i <= l; i++)
            f[i] = i;
        for (int i = 0; i < l; i++) {
            int p = ff(edges[i][0]), q = ff(edges[i][1]);
            if (p == q)
                return edges[i];
            f[ff(p)] = ff(q);
        }
        return {};
    }
};