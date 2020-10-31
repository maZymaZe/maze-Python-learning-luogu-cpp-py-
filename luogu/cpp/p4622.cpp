#include<cstdio>
#include<cstring>

const int MOD = 1e9 + 7,NMAX=1e5 + 7;
int n,a[NMAX],dp[2][NMAX],cnt=0,sz=2;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(a[1]>0||a[n]>0){
        printf("0\n");
        return 0;
    }
    a[1]=a[n]=0;
    dp[1][0]=1;
    while(sz<=n){
        int up=sz;
        if(up>n/2){
            up=n-up+1;
        }
        for(int i=0;i<up;i++){
            if(a[sz]==i||a[sz]==-1){
                dp[cnt][i]=((long long)(i?dp[cnt^1][i-1]:0)+dp[cnt^1][i]+dp[cnt^1][i+1])%MOD;
            }
        }
        cnt^=1;
        sz++;
        memset(dp[cnt],0,sizeof(dp[cnt]));
    }
    printf("%d",dp[cnt^1][0]);
    return 0;
}