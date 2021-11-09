class Solution {
   public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int l;
    void dfs(int prepos, vector<int>& candidates, int target) {
        if (target < 0)
            return;
        if (0 == target) {
            ans.emplace_back(tmp);
            return;
        }
        for (int i = prepos; i < l && candidates[i] <= target; i++) {
            if (candidates[i] > target)
                break;
            if (i > prepos && candidates[i] == candidates[i - 1])
                continue;
            tmp.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i]);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        l = candidates.size();
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return ans;
    }
};