class Solution {
   public:
    typedef pair<int, int> pii;
    pii sub(pii a, pii b) { return {a.first - b.first, a.second - b.second}; }
    int cross(pii a, pii b) {
        return (a.first * b.second) - (a.second * b.first);
    }
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {
        int n = points.size();
        vector<int> vis(n);
        vector<pii> po;
        vector<int> order;
        for (int i = 0; i < n; i++) {
            po.push_back({points[i][0], points[i][1]});
        }
        int s = 0;
        for (int i = 1; i < n; i++) {
            if (po[i] < po[s]) {
                s = i;
            }
        }
        vis[s] = 1;
        order.push_back(s);
        int len = direction.size();
        for (int i = 0; i < len; i++) {
            int nx = -1;
            if (direction[i] == 'L') {
                for (int j = 0; j < n; j++) {
                    if (!vis[j]) {
                        if (nx == -1 ||
                            cross(sub(po[nx], po[s]), sub(po[j], po[s])) < 0) {
                            nx = j;
                        }
                    }
                }
            } else if (direction[i] == 'R') {
                for (int j = 0; j < n; j++) {
                    if (!vis[j]) {
                        if (nx == -1 ||
                            cross(sub(po[nx], po[s]), sub(po[j], po[s])) > 0)
                            nx = j;
                    }
                }
            }
            vis[nx] = 1;
            order.push_back(nx);
            s = nx;
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                order.push_back(i);
            }
        }
        return order;
    }
};