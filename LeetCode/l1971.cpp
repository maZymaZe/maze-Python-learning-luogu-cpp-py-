class Solution {
   public:
    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination) {
        vector<int> f(n);
        function<int(int)> ff = [&](int x) {
            return f[x] == x ? x : f[x] = ff(f[x]);
        };
        for (int i = 0; i < n; i++)
            f[i] = i;
        for (auto& it : edges) {
            f[ff(it[0])] = ff(it[1]);
        }
        return ff(source) == ff(destination);
    }
};