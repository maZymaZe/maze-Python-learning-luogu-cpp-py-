class Solution {
   public:
    vector<int> memo;
    int findmin(int cur, vector<vector<int>>& richer, vector<int>& quiet) {
        if (memo[cur] != INT_MAX)
            return memo[cur];
        int res = cur;
        for (auto& p : richer[cur]) {
            int minp = findmin(p, richer, quiet);
            if (quiet[minp] < quiet[res])
                res = minp;
        }
        return memo[cur] = res;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> g(n);

        for (auto& v : richer)
            g[v[1]].push_back(v[0]);

        memo = vector<int>(n, INT_MAX);
        for (int cur = 0; cur < n; cur++) {
            findmin(cur, g, quiet);
        }
       
        for (int i = 0; i < n; i++) {
            if (memo[i] == INT_MAX)
                memo[i] = i;
        }

        return memo;
    }
};