#include<algorithm>
#include<cstdio>
using namespace std;
int n,a[100006],dp[100006];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    dp[1]=a[1];
    if(n>1)dp[2]=a[2];
    if(n>2)dp[3]=a[3]+a[2]+a[1];
    for(int i=4;i<=n;i++){
        dp[i]=min(dp[i-1]+a[1]+a[i],dp[i-2]+a[i]+a[1]+2*a[2]);
    }
    printf("%d\n",dp[n]);
    return 0;
}