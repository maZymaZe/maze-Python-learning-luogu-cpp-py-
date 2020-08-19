#include <cstdio>
#include <queue>
#include<algorithm>
using namespace std;
const int MMAX = 1e5 + 10, NMAX = 1e4 + 10;
struct edge {
    int u, v, nx;
} e[MMAX],ne[MMAX];
int t1, t2, h[NMAX], val[NMAX], n, m,nh[NMAX];
int low[NMAX], dfn[NMAX], vis[NMAX],sd[NMAX];
int stk[NMAX], top = 0, tm = 0;
int indo[NMAX],dist[NMAX];
void tarjan(int x) {
    low[x] = dfn[x] = ++tm;
    stk[++top] = x, vis[x] = 1;
    for (int i = h[x]; i; i = e[i].nx) {
        int y = e[i].v;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) {
            low[x] = min(low[x], low[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        while (y=stk[top--]){
            sd[y]=x;
            vis[y]=0;
            if(x==y)break;
            val[x]+=val[y];
        }
    }
}
int topo(){
    queue<int> q;
    int tot=0;
    for(int i = 1; i <= n; i++){
        if(sd[i]==i&&indo[i]==0){
            q.push(i);
            dist[i]=val[i];
        }
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=nh[x]; i; i = ne[i].nx){
            int y = ne[i].v;
            dist[y]=max(dist[y],dist[x]+val[y]);
            indo[y]--;
            if(indo[y]==0)q.push(y);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    if(dist[i]>ans)ans=dist[i];
    return ans;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t1, &t2);
        e[i] = {t1, t2, h[t1]};
        h[t1] = i;
    }
    for(int i = 1; i <= n; i++)if(!dfn[i])tarjan(i);
    int ne_cnt=0;
    for(int i=1;i<=m;i++){
        int nx=sd[e[i].u],ny=sd[e[i].v];
        if(nx!=ny){
            ne[++ne_cnt]={nx,ny,nh[nx]};
            nh[nx]=ne_cnt;indo[ny]++;
        }
    }
    printf("%d\n",topo());
    return 0;
}