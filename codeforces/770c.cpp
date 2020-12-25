#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

const int NMAX=1e5+10;
int n,k,keyc[NMAX],h[NMAX],ah[NMAX],vis[NMAX],vis2[NMAX],cnt=0,acnt=0,vcnt=0;
int sp[NMAX],ind[NMAX];
struct EDGE{
    int u,v,nx;
}e[NMAX],ae[NMAX];
void add(int u,int v){
    e[++cnt]={u,v,h[u]};
    h[u]=cnt;
}
void aadd(int u,int v){
    ae[++acnt]={u,v,ah[u]};
    ah[u]=acnt;
}
struct NODE{
    int u,ord;
}tp,tm;
struct cmp{
    bool operator()(const NODE& a, const NODE& b){
        return a.ord<b.ord;
    }
};
queue<int> q;
priority_queue<NODE,vector<NODE>,cmp> pq;
stack<int> st;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&sp[i]);
    }
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&ind[i]);
        for(int j=1;j<=ind[i];j++){
            scanf("%d",&t);
            aadd(i,t);
            add(t,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!ind[i])q.push(i);
    }
    while(!q.empty()){
        int hd=q.front();
        q.pop();
        vis[hd]=++vcnt;
        for(int i=h[hd];i;i=e[i].nx){
            int v=e[i].v;
            ind[v]--;
            if(!ind[v])q.push(v);

        }
    }
    for(int i=1;i<=k;i++){
        if(!vis[sp[i]]){
            printf("-1\n");
            return 0;
        }
        tm={sp[i],vis[sp[i]]};
        pq.push(tm);
    }
    int ans=0;
    while(!pq.empty()){
        tp=pq.top();pq.pop();
        if(vis2[tp.u])continue;
        vis2[tp.u]=1;
        st.push(tp.u);
        ans++;
        for(int i=ah[tp.u];i;i=ae[i].nx){
            int v=ae[i].v;
            tm.u=v,tm.ord=vis[v];
            pq.push(tm);
        }
    }
    printf("%d\n",ans);
    while(!st.empty()){
        printf("%d ",st.top());
        st.pop();
    }
    return 0;
}