#include<cstdio>
long long f[1000006],n,mod=1000000007;
long long qp(long long x,long long y){
    long long ans=1;
    while(y){
        if(y&1)ans=ans*x%mod;
        x=x*x%mod;
        y/=2;
    }
    return ans;
}
int main(){
    scanf("%lld", &n);
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]*(4*i-2)%mod*qp(i+1,mod-2)%mod;
    }
    printf("%lld",f[n]);
    return 0;
}