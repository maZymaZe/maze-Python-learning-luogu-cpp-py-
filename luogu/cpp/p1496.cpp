#include<cstdio>
#include<algorithm>
using namespace std;
struct pa{
    long long l,r;
    bool operator <(const pa&x){return l<x.l;}
}p[20004];
long long n,ll,rr,ans=0;
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&p[i].l,&p[i].r);
        p[i].r--;
    }
    sort(p+1,p+n+1);
    ll=p[1].l;rr=p[1].r;
    for(int i=2;i<=n;i++){
        if(p[i].l>rr){
            ans+=rr-ll+1;
            ll=p[i].l;rr=p[i].r;
        }
        else{
            rr=max(rr,p[i].r);
        }
    }
    ans+=rr-ll+1;
    printf("%lld",ans);
    return 0;
}