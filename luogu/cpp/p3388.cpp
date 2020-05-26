#include<cstdio>
#include<algorithm>
using namespace std;
struct edge{
    int u,v,nx;
}e[200005];
int t1,t2,h[20004]={0},n,m,DFN[20004],LOW[20004];
int idx=0,ans=0,del[20005]={0};
void tarjan(int u,int fa){
    DFN[u]=LOW[u]=++idx;
    int child=0;
    for(int i=h[u]; i; i = e[i].nx){
        int v=e[i].v;
        if(!DFN[v]){
            child++;
            tarjan(v,u);
            LOW[u]=min(LOW[u],LOW[v]);
            if((fa==-1&&child>1)||(fa!=-1&&LOW[v]>=DFN[u])){
                if(del[u]==0){
                    ans++;del[u]=1;
                }
            }
        }
        LOW[u]=min(DFN[v],LOW[u]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        e[(i << 1) - 1].u = t1;
        e[(i << 1) - 1].v = t2;
        e[(i << 1) - 1].nx = h[t1];
        h[t1] = (i << 1) - 1;
        e[(i << 1)].u = t2;
        e[(i << 1)].v = t1;
        e[(i << 1)].nx = h[t2];
        h[t2] = (i << 1);
    }
    for(int i=1;i<=n;i++){
        if(DFN[i]==0){
            tarjan(i,-1);
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(del[i]){
            printf("%d ",i);
        }
    }
    return 0;
}