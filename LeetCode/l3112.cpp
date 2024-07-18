struct PR {
    int id, v;
    bool operator<(const PR& x) const { return v > x.v; }
};
class Solution {
   public:
    vector<int> minimumTime(int n,
                            vector<vector<int>>& edges,
                            vector<int>& disappear) {
        vector<vector<PR>> e(n);
        for (const auto& i : edges) {
            e[i[0]].push_back({i[1], i[2]});
            e[i[1]].push_back({i[0], i[2]});
        }
        const int INF = 0x3f3f3f3f;
        vector<int> dis(n, INF), vis(n);
        dis[0] = 0;
        vis[0] = 1;

        priority_queue<PR> pq;
        for (const auto& i : e[0]) {
            pq.push(i);
        }
        while (!pq.empty()) {
            PR p = pq.top();
            pq.pop();
            if (vis[p.id])
                continue;
            vis[p.id] = 1;
            if (p.v >= disappear[p.id])
                continue;
            dis[p.id] = p.v;
            for (const auto& i : e[p.id]) {
                if (!vis[i.id])
                    pq.push({i.id, p.v + i.v});
            }
        }
        for (int i = 0; i < n; i++) {
            if (dis[i] == INF)
                dis[i] = -1;
        }
        return dis;
    }
};