#define MAX 100005
#define EMAX 200005
#define INF 2000000000
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;
struct pr{
    int d,p;
};
struct edge{
    int u,v,l;
    int nx;
}e[EMAX];
struct cmp{
    bool operator()(pr a,pr b){
        return a.d>b.d;
    }
};
priority_queue<pr,vector<pr>,cmp>  q;
int head[MAX],vis[MAX],dis[MAX],cnt,n,m,s,t1,t2,t3;
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        e[i].u=t1;e[i].v=t2;e[i].l=t3;
        e[i].nx=head[e[i].u];
        head[e[i].u]=i;
    }
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        pr now=q.top();
        q.pop();
        if(vis[now.p])continue;
        vis[now.p]=1;
        for(int i=head[now.p];i;i=e[i].nx){
            int vv=e[i].v;
            if(dis[vv]>dis[now.p]+e[i].l){
                dis[vv]=dis[now.p]+e[i].l;
                q.push({dis[vv],vv});
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    return 0;
}

