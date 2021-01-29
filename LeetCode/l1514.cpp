struct EDGE {
    int u, v, nx;
    double w;
};
vector<double> dis;
struct cmp {
    bool operator()(const int& a, const int& b) { return dis[a] < dis[b]; }
};
class Solution {
   public:
    priority_queue<int, vector<int>, cmp> q;
    vector<int> h;
    vector<int> v;
    vector<EDGE> e;
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start,
                          int end) {
        h.resize(n + 1);
        dis.resize(n + 1);
        dis.clear();
        v.resize(n + 1);
        int l = edges.size();
        e.push_back({0, 0, 0, 0});
        for (int i = 0; i < l; i++) {
            e.push_back(
                {edges[i][0], edges[i][1], h[edges[i][0]], succProb[i]});
            h[edges[i][0]] = e.size() - 1;
            e.push_back(
                {edges[i][1], edges[i][0], h[edges[i][1]], succProb[i]});
            h[edges[i][1]] = e.size() - 1;
        }
        dis[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int head = q.top();
            q.pop();
            if (v[head])
                continue;
            v[head] = 1;
            for (int i = h[head]; i; i = e[i].nx) {
                int v = e[i].v;
                if (dis[v] < dis[head] * e[i].w) {
                    dis[v] = e[i].w * dis[head];
                    q.push(v);
                }
            }
        }
        return dis[end];
    }
};