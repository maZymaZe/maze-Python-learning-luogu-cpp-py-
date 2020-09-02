#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int NMAX=220,INF= 0x3f3f3f3f,VMAX=510;
int n,m,d;
struct point {
    int flag,v,l;
}G[NMAX][NMAX];
struct pr{
    int u,v;
    double t;
    const bool operator <(const pr x)const{
        if(t==x.t)return v<x.v;
        return t>x.t;
    }
};
struct PRE{
    int u,v;
}pre[NMAX][VMAX];
double dis[NMAX][VMAX];
int vis[NMAX][VMAX];
priority_queue<pr> que;
void dij(){
    memset(dis,0x7f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    dis[0][70]=0;
    que.push({0,70,0});
    while(!que.empty()){
        pr now=que.top();
        que.pop();
        int i=now.u,j=now.v;
        if(vis[i][j])continue;
        vis[i][j]=1;
        for(int k=0;k<n;k++){
            if(G[i][k].flag){
                if(!G[i][k].v){
                    if(dis[i][j]+1.0*G[i][k].l/j<dis[k][j]){
                        dis[k][j]=dis[i][j]+1.0*G[i][k].l/j;
                        que.push({k,j,dis[k][j]});
                        pre[k][j].u=i;
                        pre[k][j].v=j;
                    }
                }
                else{
                    int v=G[i][k].v;
                    if(dis[i][j]+1.0*G[i][k].l/v<dis[k][v]){
                        dis[k][v]=dis[i][j]+1.0*G[i][k].l/v;
                        que.push({k,v,dis[k][v]});
                        pre[k][v].u=i;
                        pre[k][v].v=j;
                    }
                }
            }
        }
    }
}
void print(int u, int v){
    if(pre[u][v].u!=-1)print(pre[u][v].u,pre[u][v].v);
    printf("%d ",u);
}
int main(){
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++){
        int t1,t2,t3,t4;
        scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
        G[t1][t2]={1,t3,t4};
    }
    dij();
    double mint=INF;
    int s;
    for(int i=0;i<=500;i++){
        if(dis[d][i]<mint)mint=dis[d][i],s=i;
    }
    print(d,s);
    return 0;
}