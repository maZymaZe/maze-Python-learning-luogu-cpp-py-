struct edge {
    int u, v, nx;
};
class Solution {
   public:
    int h[10002] = {0}, sz[10002] = {0}, n;
    edge e[20002];
    vector<int> ans;
    int pdfs(int root, int dep, int fa) {
        if (!root)
            return 0;
        ans[0] += dep;
        int ts = 1;
        for (int i = h[root]; i; i = e[i].nx) {
            if (e[i].v != fa)
                ts += pdfs(e[i].v, dep + 1, root);
        }
        return sz[root] = ts;
    }
    void dfs(int root, int fa) {
        for (int i = h[root]; i; i = e[i].nx) {
            if (e[i].v != fa) {
                ans[e[i].v - 1] = ans[e[i].u - 1] - 2 * sz[e[i].v] + n;
                dfs(e[i].v, root);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        for (int i = 1; i < N; i++) {
            e[i] = {edges[i - 1][0] + 1, edges[i - 1][1] + 1,
                    h[edges[i - 1][0] + 1]};
            h[edges[i - 1][0] + 1] = i;
            e[i + N - 1] = {edges[i - 1][1] + 1, edges[i - 1][0] + 1,
                            h[edges[i - 1][1] + 1]};
            h[edges[i - 1][1] + 1] = i + N - 1;
        }
        ans.resize(N);
        pdfs(1, 0, 0);
        dfs(1, 0);
        return ans;
    }
};