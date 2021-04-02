#include<cstdio>
#include<cmath>
const int NMAX = 1e5 + 10;
typedef long long ll;
ll n,m,s[NMAX];
double ans=0;
ll q[NMAX],t,h;
double k(ll x,ll y){
    return (s[y]-s[x])*1.0/(y-x);
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1,x;i<=n;i++){
        scanf("%lld",&x);
        s[i]=s[i - 1]+x;
    }
    for(ll i=m;i<=n;i++){
        while(t-h>=2&&k(i-m,q[t-1])<k(i-m,q[t-2]))t--;
        q[t++]=i-m;
        while(t-h>=2&&k(i,q[h])<k(i,q[h+1]))h++;
        ans=fmax(ans,k(i,q[h]));
    }
    printf("%lld\n",(ll)floor(ans*1000));
    return 0;
}
