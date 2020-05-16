class Solution {
public:
    int minDistance(string word1, string word2) {
     
    int n1=word1.size(),n2=word2.size(),dp[501][501]={0};
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(word1[i]==word2[j])dp[i+1][j+1]=dp[i][j]+1;
            else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    return n1+n2-2*dp[n1][n2];
    }
};