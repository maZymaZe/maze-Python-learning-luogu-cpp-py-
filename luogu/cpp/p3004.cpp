#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=5002;
int n,a[NMAX],dp[NMAX],sum[NMAX];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i - 1] +a[i];
        dp[i]=a[i];
    }
    for(int i=2;i<=n;i++){
        for(int l=1;l<=n-i+1;l++){
            dp[l]=max(a[l]+sum[l+i-1]-sum[l]-dp[l+1],a[l+i-1]+sum[l+i-2]-sum[l-1]-dp[l]);
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}