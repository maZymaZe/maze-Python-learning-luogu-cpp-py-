class Solution {
public:
    int c0[602]= {0},c1[602]= {0},l,dp[102][102]= {0},ans=0;
    int findMaxForm(vector<string>& strs, int m, int n) {
        l= strs.size();
        for(int i=0;i<l;i++){
            for(int j=strs[i].size()-1;j>=0;j--){
                if(strs[i][j]=='0')c0[i]++;
                else c1[i]++;
            }    
        }
        for(int i=0;i<l;i++){
            for(int j=m;j>=c0[i];j--){
                for(int k=n;k>=c1[i];k--){
                    dp[j][k]=max(dp[j][k],dp[j-c0[i]][k-c1[i]]+1);
                    ans=max(ans,dp[j][k]);
                }
            }
        }
        return ans;
        
    }
};