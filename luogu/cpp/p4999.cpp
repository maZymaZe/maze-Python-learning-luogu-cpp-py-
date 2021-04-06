#include<cstdio>
typedef long long ll;
const ll MOD = 1e9 + 7;
ll l,r,T,dg[30],ts[30],ps[30],pd;
ll query(ll x){
    if(x<10)return ps[x];
    pd=0;
    ll t=0;
    while(x){
        dg[++pd]=x%10;
        t+=dg[pd];
        x /= 10;
    }
    ll pre=0,sum=0;
    for(ll i=pd;i>0;i--){
        ll fdnb;
        if(i>1)fdnb=ts[i-1]%MOD*pre*(dg[i])%MOD+ts[i-2]%MOD*ps[9]*(i-1)*(dg[i])%MOD+ts[i-1]%MOD*ps[dg[i]-1];
        else fdnb=ps[dg[i]]+pre*(dg[i]+1);
        sum=(sum+fdnb)%MOD;
        pre+=dg[i];
    }
    return (sum)%MOD;
}
int main(){
    ts[0]=1;
    for(int i=1;i<18;i++)ts[i]=ts[i-1]*10;
    ps[0]=0;
    for(int i=1;i<=9;i++)ps[i]=ps[i-1]+i;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",(query(r)+MOD-query(l-1))% MOD);
    }
    return 0;
}
