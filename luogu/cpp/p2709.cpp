#include <cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e4+5;
struct question{
    int id,l,r,in;
}q[MAXN];
int n,m,k,x,y,a[MAXN],len,cnt[MAXN],ans[MAXN],tot=0;
bool cmp(const question&a,const question&b){
    if(a.in^b.in)return a.in<b.in;
    return (a.in&1)?a.r<b.r:a.r>b.r;
}
void del(int x){
    tot-=cnt[a[x]]*cnt[a[x]];
    cnt[a[x]]--;
    tot+=cnt[a[x]]*cnt[a[x]]; 
}
void ins(int x){
    tot-=cnt[a[x]]*cnt[a[x]];
    cnt[a[x]]++;
    tot+=cnt[a[x]]*cnt[a[x]]; 
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].in=(q[i].l-1)/len+1;
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    int ll=1,rr=0;
    for(int i=1;i<=m;i++){
        x=q[i].l,y=q[i].r;
        while(ll<x)del(ll++);
        while(ll>x)ins(--ll);
        while(rr>y)del(rr--);
        while(rr<y)ins(++rr);
        ans[q[i].id]=tot;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}