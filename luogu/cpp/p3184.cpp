#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
int n,q,ppos[MAXN],pql[MAXN],pqr[MAXN],dis[MAXN*3],nmp[MAXN*3];
int p=0,sum[3*MAXN];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&ppos[i]),dis[++p]=ppos[i];
    for(int i=1;i<=q;i++)scanf("%d%d",&pql[i],&pqr[i]),dis[++p]=pql[i],dis[++p]=pqr[i];
    sort(dis+1,dis+1+p);
    int* tot=unique(dis+1,dis+p+1);
    for(int i=1;i<=n;i++){
        nmp[lower_bound(dis+1,tot,ppos[i])-dis]++;
    }
    for(int i=1;i<3*MAXN;i++){
        sum[i]=sum[i - 1] +nmp[i];
    }
    for(int i=1;i<=q; i++){
        printf("%d\n",sum[lower_bound(dis+1,tot,pqr[i])-dis]-sum[lower_bound(dis+1,tot,pql[i])-dis-1]);
    }
    return 0;
}