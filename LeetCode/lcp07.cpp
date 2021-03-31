class Solution {
public:
    vector<int> mp[12];
    int dp[12][12];
    int numWays(int n, vector<vector<int>>& relation, int k) {
        for(auto &i:relation){
            mp[i[0]].push_back(i[1]);
        }
        dp[0][0]=1;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                for(auto &l:mp[j]){
                    dp[i+1][l]+=dp[i][j];
                }
            }
        }
        return dp[k][n-1];
    }
};