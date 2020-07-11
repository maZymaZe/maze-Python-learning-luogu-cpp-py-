class Solution {
public:
    vector<double> twoSum(int n) {
        vector<vector<double> > dp(n+1,vector<double>(6*n+1));
        for(int i=1;i<7;i++)dp[1][i]=1.0/6;

        for(int i=2;i<=n;i++){
            for(int j=i;j<=6*i;j++){
                for(int k=1;k<7;k++){
                    if(j-k>=i-1)dp[i][j]+=(1.0/6)*dp[i-1][j-k];
                }
            }
        }
        vector<double> ans;
        for(auto i:dp[n])
        if(i!=0)ans.push_back(i);
        return ans; 
    }
};