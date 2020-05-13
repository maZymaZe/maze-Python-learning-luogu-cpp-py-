#include<cstdio>
#include<cmath>
#define mod (10000)
long long qpow(long long a, long long b,long long c){
    long long ans=1;
    while(b){
        if(b&1)ans=ans*a%c;
        a=a*a%c;b>>=1;
    }
    return ans%c;
}
long long t,sum[10005],a,b;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&a,&b);
        for(int i=1;i<=10000;i++){
            sum[i]=(sum[i-1]+qpow(i,b,mod))%mod;
        }
        long long ans=(a/10000*sum[10000]+sum[a%mod])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}