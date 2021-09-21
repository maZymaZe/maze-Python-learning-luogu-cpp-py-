class Solution {
   public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> G(n, vector<int>());
        for (auto& x : paths)
            G[x[0] - 1].push_back(x[1] - 1), G[x[1] - 1].push_back(x[0] - 1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            set<int> c{1, 2, 3, 4};
            for (auto j : G[i])
                c.erase(ans[j]);
            ans[i] = *c.begin();
        }
        return ans;
    }
};