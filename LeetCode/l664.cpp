class Solution {
public:
    int dfs(vector<vector<int>> &dp,string&s,int i,int j){
        if(i>j)return 0;
        if(!dp[i][j]){
            int ans=dfs(dp,s,i+1,j)+1;
            for(int k=i+1;k<=j;k++){
                if(s[k]==s[i]){
                    ans=min(ans,dfs(dp,s,i,k-1)+dfs(dp,s,k+1,j));
                }
            }
            dp[i][j]=ans;
        }
        return dp[i][j];
    }
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        return dfs(dp,s,0,n-1);
    }
};