#include<algorithm>
#include<cstdio>
using namespace std;
struct man{
    long long l,r;
    int d;
}c[20005];
int cmp(const man&a,const man&b){
    if(a.d>b.d)return 1;
    else if(a.d==b.d)return min(a.l,b.r)<min(b.l,a.r);
    return 0;
}
int n,m;
long long tot=0,pre;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        for(int j=1;j<=m;j++){
            scanf("%lld%lld",&c[j].l,&c[j].r);
            if(c[j].l<c[j].r)c[j].d=1;
            if(c[j].l==c[j].r)c[j].d=0;
            if(c[j].l>c[j].r)c[j].d=-1;
        } 
        sort(c+1,c+1+m,cmp);
        pre=c[1].l+c[1].r;
        tot=c[1].l;
        for(int j=2;j<=m;j++){
            tot+=c[j].l;
            pre=max(pre,tot)+c[j].r;
        }
        printf("%lld\n",pre);
    }
    return 0;
}