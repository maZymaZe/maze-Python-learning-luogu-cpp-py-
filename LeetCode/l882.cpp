struct pr {
    int p, d;
    bool operator<(const pr& x) const {
        return (d == x.d) ? (p > x.p) : (d > x.d);
    }
};
class Solution {
   public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        priority_queue<pr> q;
        vector<vector<pr>> e(n);
        for (auto& it : edges) {
            e[it[0]].push_back({it[1], 1 + it[2]});
            e[it[1]].push_back({it[0], 1 + it[2]});
        }
        vector<int> dis(n, 0x3f3f3f3f), vis(n);
        dis[0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int x = q.top().p, y = q.top().d;
            q.pop();
            if (vis[x])
                continue;
            vis[x] = 1;
            for (auto& it : e[x]) {
                if (dis[it.p] > dis[x] + it.d) {
                    dis[it.p] = dis[x] + it.d;
                    q.push({it.p, dis[it.p]});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] <= maxMoves)
                ans++;
        }
        for (auto& it : edges) {
            ans += min(it[2], max(maxMoves - dis[it[0]], 0) +
                                  max(maxMoves - dis[it[1]], 0));
        }
        return ans;
    }
};