class Solution {
   public:
    vector<vector<int>> modifiedGraphEdges(int n,
                                           vector<vector<int>>& edges,
                                           int source,
                                           int destination,
                                           int target) {
        vector<pair<int, int>> g[n];
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];
            g[x].emplace_back(y, i);
            g[y].emplace_back(x, i);  // 建图，额外记录边的编号
        }

        int dis[n][2], delta, vis[n];
        memset(dis, 0x3f, sizeof(dis));
        dis[source][0] = dis[source][1] = 0;
        auto dijkstra = [&](int k) {  // 这里 k 表示第一次/第二次
            memset(vis, 0, sizeof(vis));
            for (;;) {
                // 找到当前最短路，去更新它的邻居的最短路
                // 根据数学归纳法，dis[x][k] 一定是最短路长度
                int x = -1;
                for (int i = 0; i < n; ++i)
                    if (!vis[i] && (x < 0 || dis[i][k] < dis[x][k]))
                        x = i;
                if (x == destination)  // 起点 source 到终点 destination
                                       // 的最短路已确定
                    return;
                vis[x] = true;  // 标记，在后续的循环中无需反复更新 x
                                // 到其余点的最短路长度
                for (auto [y, eid] : g[x]) {
                    int wt = edges[eid][2];
                    if (wt == -1)
                        wt = 1;  // -1 改成 1
                    if (k == 1 && edges[eid][2] == -1) {
                        // 第二次 Dijkstra，改成 w
                        int w = delta + dis[y][0] - dis[x][1];
                        if (w > wt)
                            edges[eid][2] = wt = w;  // 直接在 edges 上修改
                    }
                    // 更新最短路
                    dis[y][k] = min(dis[y][k], dis[x][k] + wt);
                }
            }
        };

        dijkstra(0);
        delta = target - dis[destination][0];
        if (delta < 0)  // -1 全改为 1 时，最短路比 target 还大
            return {};

        dijkstra(1);
        if (dis[destination][1] < target)  // 最短路无法再变大，无法达到 target
            return {};

        for (auto& e : edges)
            if (e[2] == -1)  // 剩余没修改的边全部改成 1
                e[2] = 1;
        return edges;
    }
};
