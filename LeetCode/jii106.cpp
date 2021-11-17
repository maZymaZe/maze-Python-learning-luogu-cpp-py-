int ff(int x, vector<int>& f) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x], f);
}
class Solution {
   public:
    bool isBipartite(vector<vector<int>>& graph) {
        int l = graph.size();
        vector<int> f(2 * l + 1);
        for (int i = 1; i <= 2 * l; i++) {
            f[i] = i;
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (ff(i + 1, f) == ff(graph[i][j] + 1, f) ||
                    ff(i + 1 + l, f) == ff(graph[i][j] + 1 + l, f)) {
                    return false;
                }
                f[ff(i + 1, f)] = ff(graph[i][j] + 1 + l, f);
                f[ff(graph[i][j] + 1, f)] = ff(i + 1 + l, f);
            }
        }
        for (int i = 0; i < l; i++) {
            if (ff(i + 1, f) == ff(i + 1 + l, f))
                return false;
        }
        return true;
    }
};