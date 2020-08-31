#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct tree {
    int v,d;
    bool operator<(const tree& x){
        return d> x.d||(d==x.d&&v>x.v);
    }
}ts[1003];
int n,k,ans,dp[1003][1003];
int main(){
    scanf("%d%d",&n,&k);
    while(n!=0){
        for(int i=1;i<=n;i++)scanf("%d",&ts[i].v);
        for(int i=1;i<=n;i++)scanf("%d",&ts[i].d);
        ans=0;
        memset(dp,0,sizeof(dp));
        sort(ts+1,ts+1+n);
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                int x=ts[j].v-ts[j].d*(i-1);
                if(x<0)x=0;
                dp[j][i]=max(dp[j-1][i],dp[j-1][i-1]+x);
            }
        }
        for(int i=1;i<=k;i++)ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
        scanf("%d%d",&n,&k);
    }
    return 0;
}