struct EDGE {
    int v, nx, val;
};
void add(vector<EDGE>& x, vector<int>& h, int u, int v, int ep, int s) {
    x[ep] = {v, h[u], s};
    h[u] = ep;
}
class Solution {
   public:
    vector<EDGE> e;
    vector<int> h;
    int ans = 0;
    void dfs(int root, int fa) {
        for (int i = h[root]; i; i = e[i].nx) {
            if (e[i].v != fa) {
                ans += e[i].val;
                dfs(e[i].v, root);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int l = connections.size();
        ans = 0;
        e.resize(l * 2 + 1);
        h.resize(n);
        int ep = 0;
        for (int i = 0; i < l; i++) {
            add(e, h, connections[i][0], connections[i][1], ++ep, 1);
            add(e, h, connections[i][1], connections[i][0], ++ep, 0);
        }
        dfs(0, -1);
        return ans;
    }
};