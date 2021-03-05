#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=102,INF=0x3f3f3f3f,MMAX=1e6+10;
int d[NMAX][NMAX],n,m,tot,p[MMAX],dis,ans[MMAX];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&d[i][j]);
            if(!d[i][j]&&i!=j)d[i][j]=INF;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&p[i]);
    int x=p[1];
    ans[++tot]=x;
    for(int i=2;i<=m;i++){
        dis+=d[p[i-1]][p[i]];
        if(d[x][p[i]]<dis)x=p[i-1],ans[++tot]=x,dis=d[x][p[i]];
    }
    ans[++tot]=p[m];
    printf("%d\n",tot);
    for(int i=1;i<=tot; i++)printf("%d ",ans[i]);
    return 0;
}