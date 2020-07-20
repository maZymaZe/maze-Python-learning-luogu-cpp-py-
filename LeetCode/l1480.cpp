class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int l=nums.size();
        vector<int> ans(l);
        ans[0]=nums[0];
        for(int i=1;i<l;i++){
            ans[i]=ans[i-1]+nums[i];
        }
        return ans;
    }
};