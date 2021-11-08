class Solution {
   public:
    vector<vector<int>> ans;
    void dfs(int pre, int pos, int& n, int& k, vector<int>& tmp) {
        if (pos == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = pre + 1; i <= n; i++) {
            tmp[pos] = i;
            dfs(i, pos + 1, n, k, tmp);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp(k);
        dfs(0, 0, n, k, tmp);
        return ans;
    }
};