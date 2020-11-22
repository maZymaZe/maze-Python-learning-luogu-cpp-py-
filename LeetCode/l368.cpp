class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())return {};
        sort(nums.begin(),nums.end());
        int n=nums.size(),ma=-1,ps;
        vector<int> dp(n),p(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        p[i]=j;
                    }
                }        
            }if(dp[i]<1)dp[i]=1,p[i]=-1;
        }
        for(int i=0;i<n;i++)if(ma<dp[i])ma=dp[i],ps=i;
        vector<int> ans;
        while(ps!=-1)ans.push_back(nums[ps]),ps=p[ps];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};