class Solution {
public:
    int dp[300002][16]={0};
    bool splitArraySameAverage(vector<int>& A) {
        int tot=0,l=A.size();
        for(int i=0;i<l;i++){
            tot+=A[i];
        }
        dp[0][0]=1;
        for(int i=0;i<l;i++){
            for(int j=tot;j>=A[i];j--){
                for(int k=1;k<=l/2;k++){
                    dp[j][k]|=dp[j-A[i]][k-1];
                }
            }
        }
        bool ret=false;
        for(int i=1;i<=l/2;i++){
            int tar=i*tot;
            if(tar%l==0)tar/=l,
            ret|=dp[tar][i];
        }
        return ret;
    }
};