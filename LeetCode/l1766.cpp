class Solution {
   public:
    vector<vector<int>> e;
    int N;
    vector<vector<int>> ids, dps;
    vector<int> val, ans;
    void dfs(int cur, int fa, int d) {
        int ta = -1, md = 0;
        for (int i = 1; i <= 50; i++) {
            if (!ids[i].empty() && __gcd(i, val[cur]) == 1) {
                if (dps[i].back() > md) {
                    md = dps[i].back();
                    ta = ids[i].back();
                }
            }
        }
        ans[cur] = ta;

        ids[val[cur]].push_back(cur);
        dps[val[cur]].push_back(d);
        for (int i : e[cur]) {
            if (i != fa) {
                dfs(i, cur, d + 1);
            }
        }
        ids[val[cur]].pop_back();
        dps[val[cur]].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        N = nums.size();
        e.resize(N);
        ans.resize(N);
        val = nums;
        ids.resize(51);
        dps.resize(51);
        for (int i = 0; i < N - 1; i++) {
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, -1, 1);
        return ans;
    }
};