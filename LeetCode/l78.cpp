class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int l;
    void dfs(int p, vector<int> &nums){
        ans.push_back(tmp);
        if(p==l)return;
        for(int i=p;i<nums.size();i++){
            tmp.push_back(nums[i]);
            dfs(i+1,nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        l=nums.size();
        dfs(0,nums);
        return ans;
    }
};