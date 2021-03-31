class Solution {
public:
    int l;
    vector<int> t,u;
    vector<vector<int>> ans;
    void dfs(vector<int>&nums, int p){
        if(p==l){
            ans.push_back(t);
            return;
        }
        if(p>=1&&nums[p]== nums[p-1]&&u[p-1]==0)dfs(nums,p+1);
        else{
            u[p]=1;
            t.push_back(nums[p]);
            dfs(nums, p+1);
            u[p]=0;
            t.pop_back();
            dfs(nums, p+1);
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        l=nums.size();    
        u.resize(l);
        dfs(nums,0);
        return ans;
    }
};