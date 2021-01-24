#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,T,tot,dp[103],a[103];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tot=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            tot+=a[i];
        }
        for(int i=1;i<=n;i++){
            int t=-0x3f3f3f3f;
            for(int j=1;j<i;j++){
                if(a[i]>=a[j]){
                    t=max(t,dp[j]);
                }
            }
            dp[i]=max(t,0)+a[i];
        }
        int t=-0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            t=max(t,dp[i]);
        }
        printf("%d\n",tot-t);
    }
    return 0;
}
