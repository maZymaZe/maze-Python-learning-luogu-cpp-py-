class Solution {
   public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source,
                              int target) {
        int rs = routes.size();
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> edge(rs, vector<int>(rs));

        for (int i = 0; i < rs; i++) {
            for (int site : routes[i]) {
                for (int j : mp[site]) {
                    edge[i][j] = edge[j][i] = 1;
                }
                mp[site].push_back(i);
            }
        }

        vector<int> ans(rs, -1);
        queue<int> q;
        for (int bus : mp[source])
            ans[bus] = 1, q.push(bus);
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            for (int y = 0; y < rs; y++) {
                if (edge[h][y] && ans[y] == -1) {
                    ans[y] = ans[h] + 1;
                    q.push(y);
                }
            }
        }

        int ret = 0x3f3f3f3f;
        for (int bus : mp[target]) {
            if (ans[bus] != -1)
                ret = min(ret, ans[bus]);
        }
        return ret == 0x3f3f3f3f ? -1 : ret;
    }
};