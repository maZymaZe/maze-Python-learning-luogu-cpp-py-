class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int l;
    void dfs(int prepos,int tot,vector<int>& candidates,int &target){
        if(tot==target){
            ans.emplace_back(tmp);
            return;
        }
        for(int i=prepos;i<l;i++){
            if(tot+candidates[i]>target)continue;
            tmp.emplace_back(candidates[i]);
            dfs(i,tot+candidates[i],candidates,target);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        l=candidates.size();
        dfs(0,0,candidates,target);
        return ans;
    }
};