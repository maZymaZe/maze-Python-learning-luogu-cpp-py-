class Solution {
   public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> ind(n - m + 1, m);
        vector<vector<int>> edges(n, vector<int>());
        queue<int> q;
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < m; j++) {
                if (target[i + j] == stamp[j]) {
                    --ind[i];
                    if (ind[i] == 0)
                        q.push(i);
                } else
                    edges[i + j].push_back(i);
            }
        }
        vector<int> vis(n), res;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int i = 0; i < m; i++) {
                if (!vis[x + i]) {
                    vis[x + i] = 1;
                    for (int j : edges[x + i]) {
                        --ind[j];
                        if (ind[j] == 0)
                            q.push(j);
                    }
                }
            }
        }
        if (res.size() == n - m + 1) {
            reverse(res.begin(), res.end());
            return res;
        }
        return {};
    }
};