class Solution {
   public:
    int maxWeight(vector<vector<int>>& edges, vector<int>& val) {
        int n = val.size();
        int m = edges.size();
        vector<unordered_map<int, int>> adj(n);  // second, id
        // weight desc, time mlogm
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) {
            return val[a[0]] + val[a[1]] > val[b[0]] + val[b[1]];
        });
        int res = 0;

        int id = 0;
        for (auto& e : edges) {  // &
            adj[e[0]][e[1]] = id;
            adj[e[1]][e[0]] = id;
            id++;
        }
        for (int i = 0; i < n; i++) {
            unordered_map<int, int>& s = adj[i];
            vector<int> pos;
            int ns = s.size();

            if (ns * ns <= m) {  // degree < sqrt(m)
                for (auto [j, ji] : s) {
                    for (auto [k, ki] : s) {
                        if (j != k && adj[j].count(k) > 0) {
                            pos.emplace_back(adj[j][k]);  // edge j-k
                        }
                    }
                }
            } else {  // degree > sqrt(m)
                int j = 0;
                for (auto& e : edges) {
                    int u = e[0];
                    int v = e[1];
                    if (s.count(u) > 0 && s.count(v) > 0) {
                        pos.emplace_back(j);
                    }
                    j++;
                }
            }
            // id smaller, weight bigger.
            priority_queue<int> pq;
            for (int j : pos) {
                if (pq.size() < 3 || j < pq.top())
                    pq.push(j);  //
                if (pq.size() > 3)
                    pq.pop();
            }
            while (!pq.empty()) {
                auto& e = edges[pq.top()];
                int x = e[0];
                int y = e[1];
                int sum = val[i] + val[x] + val[y];  //
                pq.pop();
                // other edge
                for (int j : pos) {
                    auto& b = edges[j];
                    int u = b[0];
                    int v = b[1];
                    int cur = sum;
                    if (u != x && u != y)
                        cur += val[u];
                    if (v != x && v != y)
                        cur += val[v];
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
