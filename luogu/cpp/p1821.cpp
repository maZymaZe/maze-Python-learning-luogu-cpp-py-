#define MAX 1005
#define EMAX 100005
#define INF 2000000000
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct pr{
    int d,p;
};
struct edge{
    int u,v,l;
    int nx;
}e[EMAX],fe[EMAX];
struct cmp{
    bool operator()(pr a,pr b){
        return a.d>b.d;
    }
};
priority_queue<pr,vector<pr>,cmp>  q,fq;
int fvis[MAX],head[MAX],vis[MAX],dis[MAX],fdis[MAX],fhead[MAX],cnt,n,m,s,t1,t2,t3;
int ans=0;
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        e[i].u=t1;e[i].v=t2;e[i].l=t3;
        e[i].nx=head[e[i].u];
        head[e[i].u]=i;
        fe[i].u=t2;fe[i].v=t1;fe[i].l=t3;
        fe[i].nx=fhead[fe[i].u];
        fhead[fe[i].u]=i;
    }

    for(int i=1;i<=n;i++)dis[i]=INF,fdis[i]=INF;
    fdis[s]=dis[s]=0;
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
    fq.push({0,s});
    while(!fq.empty()){
        pr fnow=fq.top();
        fq.pop();
        if(fvis[fnow.p])continue;
        fvis[fnow.p]=1;
        for(int i=fhead[fnow.p];i;i=fe[i].nx){
            int vv=fe[i].v;
            if(fdis[vv]>fdis[fnow.p]+fe[i].l){
                fdis[vv]=fdis[fnow.p]+fe[i].l;
                fq.push({fdis[vv],vv});
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(dis[i]+fdis[i],ans);
    }
    printf("%d",ans);
    return 0;
}

