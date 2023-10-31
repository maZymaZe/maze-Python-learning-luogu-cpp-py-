class Solution {
   public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents,
                                            vector<int>& nums) {
        int p1 = -1, l = parents.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] == 1)
                p1 = i;
        }
        vector<int> ans(l, 1);
        if (p1 == -1)
            return ans;
        vector<int> tdl;
        while (p1 != -1) {
            tdl.push_back(p1);
            p1 = parents[p1];
        }
        vector<vector<int>> e(l, vector<int>());
        for (int i = 0; i < l; i++) {
            if (parents[i] != -1) {
                e[parents[i]].push_back(i);
            }
        }
        int l2 = tdl.size(), x = 2;
        vector<int> vis(1e5 + 2, 0);
        function<void(int, int)> dfs = [&](int node, int nosearch) {
            vis[nums[node]] = 1;
            for (int i : e[node]) {
                if (i != nosearch) {
                    dfs(i, -1);
                }
            }
        };
        for (int i = 0; i < l2; i++) {
            dfs(tdl[i], i == 0 ? -1 : tdl[i - 1]);
            while (vis[x])
                x++;
            ans[tdl[i]] = x;
        }
        return ans;
    }
};