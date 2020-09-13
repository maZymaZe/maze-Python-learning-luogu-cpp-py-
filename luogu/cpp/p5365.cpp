#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=260;
const int MONEYMAX=530000;
int n,k[NMAX],c[NMAX],tot=0;
long long dp[MONEYMAX];
long long m;
int main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]),tot+=c[i]*k[i];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=tot;j>=0;j--){
            for(int l=2;l<=k[i]&&c[i]*l<=j;l++){
                if(j>=l*c[i]){
                    dp[j]=max(dp[j],dp[j-c[i]*l]*l);
                }
            }
        }
    }
    int ans=tot;
    for(int i=tot;i>=0;i--)if(dp[i]>=m)ans=i;
    printf("%d\n",ans);
    return 0;
}