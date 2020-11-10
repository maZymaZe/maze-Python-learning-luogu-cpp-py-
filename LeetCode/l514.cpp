class Solution {
public:
    int dp[102][102];
    int findRotateSteps(string ring, string key) {
        int l=ring.length(),k=key.length();
        for(int i=0;i<l;i++){
            dp[0][i]=min(i,l-i);
        }
        for(int i=1;i<=k;i++){
            for(int j=0;j<l;j++){
                dp[i][j]=0x3f3f3f3f;
                if(ring[j]==key[i-1]){
                    for(int h=0;h<l;h++){
                        dp[i][j]=min(dp[i][j],dp[i-1][h]+min(abs(h-j),min(l-h+j,l-j+h)));
                    }
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<l;i++){
            ans=min(ans,dp[k][i]);
        }
        return ans+k;
    }
};