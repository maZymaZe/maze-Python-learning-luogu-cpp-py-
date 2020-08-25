class Solution {
public:
    int n;
    vector<int> v;
    void dfs(int t,vector<vector<int> > &ret,vector<int>& nums){
        if(t==n&&v.size()>1){ret.push_back(v);return;}
        if(t==n)return;
        if(v.empty()||nums[t]>=v.back()){
            v.push_back(nums[t]);
            
            dfs(t+1,ret,nums);
            v.pop_back();
        }
        if(v.empty()||nums[t]!=v.back())dfs(t+1,ret,nums);
    }
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        n=nums.size();
        v.clear();
        vector<vector<int>> ret;
        dfs(0,ret,nums);
        return ret;
    }
};