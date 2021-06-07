class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[3000][2]={0};
        dp[1500][1]=1;
        int l=nums.size();
        for(int i=0; i<l; i++){
            for(int j=0;j<3000;j++){
                dp[j][i&1]=0;
                if(j+nums[i]<3000&&j+nums[i]>=0){
                    dp[j][i&1]+=dp[j+nums[i]][(i&1)^1];
                }
                if(j-nums[i]<3000&&j-nums[i]>=0){
                    dp[j][i&1]+=dp[j-nums[i]][(i&1)^1];
                }
            }
        }
        return dp[1500+target][(l-1)&1];
    }
};