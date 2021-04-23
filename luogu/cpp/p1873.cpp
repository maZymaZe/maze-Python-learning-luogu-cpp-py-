#include<cstdio>
typedef long long ll;
const ll NMAX=1e6+10;

ll n,m,a[NMAX],ans;
bool ck(int x){
    ll tot=0;
    for(int i=1;i<=n;i++){
        if(a[i]>x)tot+=a[i]-x;
    }
    return tot>=m;
}
int main(){
    ll l=0,r=1000000000,mid;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    while(l<r){
        mid=(l+r+1)/2;
        if(ck(mid)){
            l=mid;ans=mid;
        }else r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}