#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7,NMAX=2e5+10;
ll qpow(ll a, ll b){
    ll ret=1;
    a%=MOD;
    b%=(MOD-1);
    while(b){
        if(b&1)ret=ret*a%MOD;
        a=a*a% MOD;
        b>>=1;
    }
    return ret;
}
ll n,cnt,x[NMAX],tmp[NMAX],a[NMAX];
int main() {
    scanf("%lld",&n);
    for(int i=1; i <= n; i++)scanf("%lld",&tmp[i]);
    sort(tmp+1,tmp+1+n);
    for(int i=1;i<=n;i++){
        if(i==1||tmp[i]!=tmp[i-1]){
            x[++cnt]=tmp[i];            
        }
        a[cnt]++;
    }
    ll M=1,ans=1;
    for(int i=1;i<=cnt;i++){
        M=M*(a[i]+1)%(2*MOD-2);
    }
    for(int i=1;i<=cnt;i++){
        ans=ans*qpow(x[i],M*a[i]/2%(2*MOD-2))% MOD;
    }
    printf("%lld\n",ans);
    return 0;
}