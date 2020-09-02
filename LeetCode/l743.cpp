struct edge {
    int u, v, nx, w;
};
struct pr {
    int p, d;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) {
        return a.d > b.d || (a.d == b.d && a.p < b.p);
    }
};
class Solution {
   public:
    const int INF = 0x3f3f3f3f;
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> h(N + 1, 0), vis(N + 1, 0), dis(N + 1, INF);
        int m = times.size();
        vector<edge> e(m + 1);
        for (int i = 0; i < m; i++)
            e[i + 1].u = times[i][0], e[i + 1].v = times[i][1],
                  e[i + 1].nx = h[times[i][0]], e[i + 1].w = times[i][2],
                  h[times[i][0]] = i + 1;
        priority_queue<pr, vector<pr>, cmp> q;
        dis[K] = 0;
        q.push({K,0});
        while (!q.empty()) {
            pr t = q.top();
            q.pop();
            if (vis[t.p])
                continue;
            vis[t.p] = 1;
            for (int i = h[t.p]; i; i = e[i].nx) {
                int vv = e[i].v;
                if (dis[vv] > dis[t.p] + e[i].w) {
                    dis[vv] = dis[t.p] + e[i].w;
                    q.push({vv,dis[vv]});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (!vis[i])
                return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};