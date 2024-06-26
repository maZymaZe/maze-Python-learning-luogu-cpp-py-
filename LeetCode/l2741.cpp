class Solution {
   public:
    int l, lim, MOD = 1e9 + 7;
    vector<int> nm;
    vector<vector<int>> pf, vis;
    int dfs(int prepos, int choice) {
        if (choice == 0)
            return 1;
        if (vis[prepos][choice])
            return pf[prepos][choice];
        vis[prepos][choice] = 1;
        int ans = 0;
        for (int i = 0; i < l; i++) {
            if (choice & (1 << i) &&
                (nm[i] % nm[prepos] == 0 || nm[prepos] % nm[i] == 0)) {
                ans = (ans + dfs(i, choice ^ (1 << i))) % MOD;
            }
        }
        return pf[prepos][choice] = ans;
    }
    int specialPerm(vector<int>& nums) {
        l = nums.size();
        lim = (1 << l);
        nm = nums;
        vis = pf = vector<vector<int>>(l, vector<int>(lim, 0));
        int ans = 0;
        for (int i = 0; i < l; i++) {
            ans = (ans + dfs(i, (lim - 1) ^ (1 << i))) % MOD;
        }
        return ans;
    }
};