class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int l=nums.size();
        vector<vector<int> > dp(l+2,vector<int>(l+2));
        for(int d=0;d<l;d++){
            for(int i=0;i+d<l;i++){
                int j=i+d;
                if(d>1){
                    dp[i][j]=0;
                    for(int k=i+1;k<j;k++){
                        dp[i][j]=max(dp[i][j],nums[i]*nums[j]*nums[k]+dp[i][k]+dp[k][j]);
                    }
                }
                else dp[i][j]=0;
            }
        }
        return dp[0][l-1];
    }
    
};