#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1400]={0};
int n,k,t,v[120],w[120],ans=0;
int main(){
    scanf("%d%d%d", &n,&t,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=t*1.3;i++){
            if(i>=w[j]){
                dp[i]=max(dp[i],dp[i-w[j]]+v[j]);
            }
        }
    }
    ans=dp[t];
    for(int i=1;i<=n;i++){
        if(w[i]>=k){
            ans=max(ans,dp[(int)((t-w[i])*1.25)]+v[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}