#include<queue>
#include<vector>
#include<cstdio>
#define MAX 1000004
#define INF 2000000000
using namespace std;
struct edge{
    int u,v,nx;
}e[4000006];
int d[MAX],head[MAX]={0},n,m,ans[MAX]={0},vis[MAX];
struct pr{
    int p,pd;
    bool operator < (const pr&x)const{
        return pd>x.pd;
    }
};
priority_queue<pr> pq;
int main(){
    scanf("%d%d",&n,&m);
    int t1,t2;
    for(int i=1;i<=n;i++)d[i]=INF;
    d[1]=0;ans[1]=1;
    pq.push({1,0});
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        if(t1==t2)continue;
        e[2*i-1]={t1,t2,head[t1]};head[t1]=2*i-1;
        e[2*i]={t2,t1,head[t2]};head[t2]=2*i;
    }
    while(!pq.empty()){
        pr w=pq.top();
        pq.pop();
        if(vis[w.p])continue;
        vis[w.p]=1;
        for(int i=head[w.p];i;i=e[i].nx){
            if(d[e[i].u]+1<d[e[i].v]){
                d[e[i].v]=d[e[i].u]+1;
                ans[e[i].v]=ans[e[i].u];
                pq.push({e[i].v,d[e[i].v]});
            }
            else if(d[e[i].u]+1==d[e[i].v]){
                ans[e[i].v]+=ans[e[i].u];
                ans[e[i].v]%=100003;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i]==INF)printf("0\n");
        else printf("%d\n",ans[i]);
    }
    return 0;
}
