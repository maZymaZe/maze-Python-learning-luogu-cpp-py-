class Solution {
   public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        auto get = [&](int x) {
            vector<int> d(n, -1);
            int p = x;
            int dis = 0;
            while (p != -1 && d[p] == -1) {
                d[p] = dis;
                p = edges[p];
                dis++;
            }
            return d;
        };
        auto d1 = get(node1);
        auto d2 = get(node2);
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] != -1 && d2[i] != -1 &&
                (res == -1 || max(d1[res], d2[res]) > max(d1[i], d2[i]))) {
                res = i;
            }
        }
        return res;
    }
};
