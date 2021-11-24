struct tp {
    int x, y, z;
    bool operator<(const tp& other) const { return x > other.x; }
};
class Solution {
   public:
    int electricCarPlan(vector<vector<int>>& paths,
                        int cnt,
                        int start,
                        int end,
                        vector<int>& charge) {
        int n = charge.size();
        vector<vector<int>> dis(n, vector<int>(cnt + 1, 0x3f3f3f3f));
        dis[start][0] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& path : paths) {
            adj[path[0]].push_back({path[1], path[2]});
            adj[path[1]].push_back({path[0], path[2]});
        }
        priority_queue<tp> pq;
        pq.push({0, start, 0});
        while (!pq.empty()) {
            int t = pq.top().x, u = pq.top().y, c = pq.top().z;
            pq.pop();
            if (t > dis[u][c])
                continue;
            if (u == end) {
                return t;
            }
            if (c < cnt) {
                int nt = t + charge[u];
                if (nt < dis[u][c + 1]) {
                    dis[u][c + 1] = nt;
                    pq.push({nt, u, c + 1});
                }
            }
            for (auto [v, w] : adj[u]) {
                if (c >= w && t + w < dis[v][c - w]) {
                    dis[v][c - w] = t + w;
                    pq.push({t + w, v, c - w});
                }
            }
        }
        return -1;
    }
};