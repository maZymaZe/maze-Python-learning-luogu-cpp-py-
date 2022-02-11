class Solution {
   public:
    vector<int> shortestAlternatingPaths(int n,
                                         vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<int> ans(n), visr(n), visl(n);
        ans[0] = 0;
        for (int i = 1; i < n; i++) {
            ans[i] = 0x3f3f3f3f;
        }
        vector<vector<int>> rnx(n), bnx(n);
        int l = redEdges.size();
        for (int i = 0; i < l; i++)
            rnx[redEdges[i][0]].push_back(redEdges[i][1]);
        l = blueEdges.size();
        for (int i = 0; i < l; i++)
            bnx[blueEdges[i][0]].push_back(blueEdges[i][1]);
        queue<int> qx, qy, qz;
        qx.push(0), qy.push(0), qz.push(0);
        qx.push(0), qy.push(1), qz.push(0);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), z = qz.front();
            ans[x] = min(ans[x], z);
            qx.pop(), qy.pop(), qz.pop();
            if (y && visl[x])
                continue;
            if (!y && visr[x])
                continue;
            if (y)
                visl[x] = 1;
            else
                visr[x] = 0;
            if (y) {
                for (auto nx : rnx[x]) {
                    qx.push(nx), qy.push(!y), qz.push(z + 1);
                }
            } else {
                for (auto nx : bnx[x]) {
                    qx.push(nx), qy.push(!y), qz.push(z + 1);
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (ans[i] == 0x3f3f3f3f)
                ans[i] = -1;
        return ans;
    }
};