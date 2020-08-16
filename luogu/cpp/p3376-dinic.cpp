#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
inline ll min(ll a, ll b) {
    return a < b ? a: b;
}
int n, m, s, t;
const ll INF = 1e18;
const int NMAX = 230;
const int MMAX = 2*5003;
int head[NMAX], nx[MMAX], ver[MMAX], tot = 1;
ll edge[MMAX], maxflow, level[NMAX];
int now[MMAX];
queue<int> q;
inline void add(int u, int v, int w) {
    ver[++tot] = v, edge[tot] = w, nx[tot] = head[u], head[u] = tot;
    ver[++tot] = u, edge[tot] = 0, nx[tot] = head[v], head[v] = tot;
}
bool bfs() {
    for (int i = 1; i <= n; i++)
        level[i] = INF;
    while (!q.empty())
        q.pop();
    q.push(s);
    level[s] = 0;
    now[s] = head[s];
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nx[i]) {
            int y = ver[i];
            if (edge[i] > 0 && level[y] == INF) {
                q.push(y);
                now[y] = head[y];
                level[y] = level[x] + 1;
                if (y == t)
                    return 1;
            }
        }
    }
    return 0;
}
ll dfs(int x, ll flow) {
    if (x == t)
        return flow;
    ll ans = 0, k, i;
    for (i = now[x]; i && flow; i = nx[i]) {
        now[x] = i;
        int y = ver[i];
        if (edge[i] > 0 && level[y] == level[x] + 1) {
            k = dfs(y,min(edge[i],flow));
            if(!k)level[y]=INF;
            edge[i] -= k;
            edge[i^1]+=k;
            ans+=k;
            flow-=k;
        }
    }
    return ans;
}
void dinic(){
    while(bfs())maxflow+=dfs(s,INF);
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    tot=1;int t1,t2,t3;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        add(t1,t2,t3);
    }
    dinic();
    printf("%lld\n",maxflow);
    return 0;
}