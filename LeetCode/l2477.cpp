class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> e(n);
        for (auto v : roads) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        long long res = 0;
        function<int(int, int)> dfs = [&](int cur, int fa) {
            int ps = 1;
            for (int ne : e[cur]) {
                if (ne != fa) {
                    int pc = dfs(ne, cur);
                    ps += pc;
                    res += (pc + seats - 1) / seats;
                }
            }
            return ps;
        };
        dfs(0, -1);
        return res;
    }
};