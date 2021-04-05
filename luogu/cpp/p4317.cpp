#include<cstdio>
long long cnt[64];
const long long MOD=1e7+7;
long long qpow(long long a, long long b){
    long long ret=1;
    while(b){
        if(b&1)ret=ret*a% MOD;
        a=a*a% MOD;
        b >>= 1;
    }
    return ret;
}
long long bits[70],n,p,cc=0;
long long dp[70][70];
int main(){
    scanf("%lld",&n);
    while(n){
        bits[++p]=n&1;
        cc+=n&1;
        n>>=1;
    }
    dp[1][0]=1;
    dp[1][1]=1;
    dp[0][0]=1;
    for(int i=2;i<=60;i++){
        dp[i][0]=1;
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    int pre1=0;
    for(int i=p;i>0;i--){
        if(bits[i]==1){            
            for(int j=0;j<i;j++){
                cnt[j+pre1]+=dp[i-1][j];
            }
            pre1++;
        }
    }
    cnt[cc]++;
    long long ans=1;
    for(int i=2;i<=60;i++)ans=ans*qpow(i,cnt[i])% MOD;
    printf("%lld",ans);
    return 0;

}