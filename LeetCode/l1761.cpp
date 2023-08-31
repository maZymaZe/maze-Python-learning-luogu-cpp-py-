class Solution {
   public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n);
        vector<vector<int>> h(n);
        vector<int> degree(n);
        for (const auto& e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].insert(y), g[y].insert(x);
            ++degree[x], ++degree[y];
        }
        for (const auto& e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            if ((degree[x] == degree[y] && x < y) || (degree[x] < degree[y])) {
                h[x].push_back(y);
            } else
                h[y].push_back(x);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j : h[i]) {
                for (int k : h[j]) {
                    if (g[i].count(k)) {
                        ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                    }
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};