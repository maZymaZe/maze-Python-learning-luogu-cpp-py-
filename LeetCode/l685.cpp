class Solution {
   public:
    int f[1001] = {0};
    int ff(int x) {
        if (f[x] == x)
            return x;
        else
            return f[x] = ff(f[x]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int l = edges.size(), flag = 0, indegree[1002] = {0}, rr;
        for (int i = 0; i < l; i++) {
            if (!indegree[edges[i][1]])
                indegree[edges[i][1]] = i+1;
            else {
                rr = i;
                flag = 1;
                break;
            }
        }
        for (int i = 1; i <= l; i++)
            f[i] = i;
        if (flag) {
            for (int i = 0; i < l; i++) {
                if (i == rr)
                    continue;
                int p = ff(edges[i][0]), q = ff(edges[i][1]);
                if (p == q) {
                    flag = 0;
                    break;
                }
                f[ff(p)] = ff(q);
            }
            if (flag)
                return edges[rr];
            return edges[indegree[edges[rr][1]]-1];

        } else {
            for (int i = 0; i < l; i++) {
                int p = ff(edges[i][0]), q = ff(edges[i][1]);
                if (p == q)
                    return edges[i];
                f[ff(p)] = ff(q);
            }
        }
        return {};
    }
};