class Solution {
public:
    int rob(vector<int>& nums) {
        int l=nums.size();
        if(l==0)return 0;
        if(l==1)return  nums[0];
        if(l==2)return max(nums[1],nums[0]);
        if(l==3)return max(nums[0]+nums[2],nums[1]);
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[1],nums[0]));
        dp.push_back(max(nums[0]+nums[2],nums[1]));
        for(int i=3;i<l;i++){
            dp.push_back(nums[i]+max(dp[i-2],dp[i-3]));
        }
        return max(dp[l-1],dp[l-2]);
    }
};