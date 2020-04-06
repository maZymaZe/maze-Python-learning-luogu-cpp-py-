#define MAX 5005
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
}e[2*EMAX];
struct cmp{
    bool operator()(pr a,pr b){
        return a.d>b.d;
    }
};
priority_queue<pr,vector<pr>,cmp>  q;
int head[MAX],vis[MAX],dis[MAX],cnt=0,n,m,s,t1,t2,t3,ans=0;
int main(){
    scanf("%d%d",&n,&m);
    s=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        e[2*i].u=t1;e[2*i].v=t2;e[2*i].l=t3;
        e[2*i].nx=head[e[2*i].u];
        head[e[2*i].u]=2*i;
        e[2*i-1].u=t2;e[2*i-1].v=t1;e[2*i-1].l=t3;
        e[2*i-1].nx=head[e[2*i-1].u];
        head[e[2*i-1].u]=2*i-1;
    }
    for(int i=1;i<=n;i++)dis[i]=INF;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()){
        pr now=q.top();
        q.pop();
        if(vis[now.p])continue;
        ans+=now.d;cnt++;
        vis[now.p]=1;
        for(int i=head[now.p];i;i=e[i].nx){
            int vv=e[i].v;
            if(dis[vv]>e[i].l&&vis[vv]==0){
                dis[vv]=e[i].l;
                q.push({dis[vv],vv});
            }
        }
    }
    if(cnt==n)printf("%d",ans);
    else printf("orz");
    return 0;
}

