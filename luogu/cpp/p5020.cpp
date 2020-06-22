#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,dp[25008],a[108],ans;
int main(){
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        ans=n;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+ 1,a+1+n);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(dp[a[i]]){
                ans--;
                continue;
            }
            for(int j=a[i];j<=a[n];j++){
                dp[j]=dp[j]|dp[j-a[i]];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}