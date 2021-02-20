#include<cstdio>
#include<cstring>
const int NMAX = 1e6 + 10;
int n,m,U[NMAX],K[NMAX];
int head[NMAX],to[NMAX],nx[NMAX],fa[NMAX],wson[NMAX],len[NMAX],dep[NMAX];
int sta[NMAX],top,ans[NMAX];
int tot,headq[NMAX],k[NMAX],id[NMAX],nxq[NMAX];
int ep=0;
inline void add(int a, int b){
    to[++ep]=b,nx[ep]=head[a],head[a]=ep;
}
inline void addq(int a, int b, int c) {
    k[++tot]=b;id[tot]=c;nxq[tot]=headq[a];headq[a]=tot;
}
void dfs(int x){ 
    sta[++top]=x;
    dep[x]=dep[fa[x]]+1;
    for(int i=headq[x];i;i=nxq[i]){
        ans[id[i]]=(top>k[i])?sta[top-k[i]]:0;
    }
    for(int i=head[x];i;i=nx[i]){
        dfs(to[i]);
        if(len[to[i]]>len[wson[x]])wson[x]=to[i];
    }
    len[x]=len[wson[x]]+1;
    --top;
}
int tmp[NMAX];
int *now=tmp;
int *dp[NMAX];
void calc(int x){
    dp[x][0]=1;
    if(wson[x]){
        dp[wson[x]]=dp[x]+1;
        calc(wson[x]);
        for(int i=head[x]; i; i = nx[i]){
            if(to[i]!=wson[x]){
                dp[to[i]]=now;now+=len[to[i]];
                calc(to[i]);
                for(int j=1;j<=len[to[i]];j++){
                    dp[x][j]+=dp[to[i]][j-1];
                }
            }
        }
        for(int i=headq[x]; i; i=nxq[i]){
            ans[id[i]]=dp[x][k[i]];
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &fa[i]);
        if(fa[i])add(fa[i],i);
    }
    scanf("%d", &m);
    for(int i=1;i<= m; i++){
        scanf("%d%d", &U[i], &K[i]);
        addq(U[i],K[i],i);
    }
    for(int i=1;i<=n;i++){
        if(!fa[i])dfs(i);
    }
    memset(headq, 0, sizeof(headq));tot=0;
    for(int i=1;i<=m;i++){
        if(ans[i])addq(ans[i],K[i],i);
    }
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<=n;i++){
        if(!fa[i]){
            dp[i]=now;now+=len[i];
            calc(i);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]<=0?0:ans[i]-1);
    }
    return 0;
}