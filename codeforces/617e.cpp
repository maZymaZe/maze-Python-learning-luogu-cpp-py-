#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int NMAX=1e6+10;
int a[NMAX];
long long sum,ans[NMAX<<1];
int block[NMAX];
int n,m,k,cnt[NMAX<<1],xorn[NMAX<<1];
struct QUERY{
    int L,R,id;
}q[NMAX];
bool cmp1(const QUERY& a, const QUERY& b){
    if(block[a.L]!=block[b.L]){
        return a.L < b.L;
    }
    return (block[a.L]&2?a.R<b.R:a.R>b.R);
}
void ins(int x){
    sum+=cnt[xorn[x]^k];
    cnt[xorn[x]]++;
}
void del(int x){
    cnt[xorn[x]]--;
    sum-=cnt[xorn[x]^k];
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int lenb=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        block[i]=(i-1)/lenb+1;
        xorn[i]=xorn[i-1]^a[i];
    }
    for(int i=1;i<=m; i++){
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].L --;
        q[i].id = i;
    }
    sort(q+1, q + 1 + m, cmp1);
    int L=1,R=0;
    for(int i=1;i<=m;i++){
        while(q[i].L<L){
            L--;
            ins(L);            
        }
        while(q[i].R>R){
            R++;
            ins(R);
        }
        while(q[i].L>L){
            del(L);
            L++;
        }
        while(q[i].R<R){
            del(R);
            R--;
        }
        ans[q[i].id]=sum;
    }
    for(int i=1;i<=m; i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}