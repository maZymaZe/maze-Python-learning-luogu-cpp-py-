#include <cstdio>
#include <cstring>
int n,t,dp[2004],a[40],m;
long long ans;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        ans=0;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=2001;j>=a[i];j--){
                dp[j]+=dp[j-a[i]];
            }
        }
        for(int i=1;i<=n;i++){
            ans+=dp[a[i]]-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}