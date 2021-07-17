#include<cstdio>
#include<algorithm>
using namespace std;
const long long MOD=998244353,NMAX=305000;
long long a[NMAX],n,ans=0,inv[NMAX]={0,1};

int main(){
    scanf("%lld",&n);
    long long nn=n*2;
    for(int i=1; i <= nn; i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+nn);
    for(int i=1; i <= n; i++){
        (ans+=a[nn-i+1]-a[i])%=MOD;
    }
    for(int i=n+1;i<=nn;i++){
        (ans*=i)%=MOD;
    }
    for(int i=2;i<=n;i++){
        inv[i]=MOD-(MOD/i)*inv[MOD%i]% MOD;
        (ans*=inv[i])%=MOD;
    }
    printf("%lld\n",ans);
    return 0;
}