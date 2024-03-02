class Solution {
   public:
    int reachableNodes(int n,
                       vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<vector<int>> e(n);
        for (const auto& ee : edges) {
            e[ee[0]].push_back(ee[1]);
            e[ee[1]].push_back(ee[0]);
        }
        int ans = 0;
        unordered_set<int> s;
        for (int i : restricted)
            s.insert(i);

        function<void(int, int)> dfs = [&](int cur, int fa) {
            ans++;
            for (int i : e[cur]) {
                if (i == fa || s.count(i)) {
                    continue;
                }
                dfs(i, cur);
            }
        };
        dfs(0, -1);
        return ans;
    }
};