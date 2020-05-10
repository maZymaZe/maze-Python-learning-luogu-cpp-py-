#include<cstdio>
#include<algorithm>
using namespace std;
const int N=(1e4+10);
const int M=(5e4+10);
int to[N<<1],pre[N<<1],val[N<<1],first[N],edge_tot;
int ff[N],f[N],d[N],son[N],size[N],top[N],id[N],rk[N],dfn_tot;
int st[N][30],lg2[N];
int a[N],n,m,q;
struct edge{
    int u,v,w;
    bool operator <(const edge&x){ return w>x.w; }
}e[M];
inline void add(int u,int v,int w)
{
	to[++edge_tot] = v;
	val[edge_tot] = w;
	pre[edge_tot] = first[u];
	first[u] = edge_tot;
}
int query(int l, int r){
    if(l>r)return 0x3f3f3f3f;
    int lg=lg2[r-l+1];
    return min(st[l][lg],st[r-(1<<lg)+1][lg]);
}
int father(int x){
    if(f[x]==x)return x;
    return f[x]=father(f[x]);
}
void merge(int x,int y){
    f[father(x)]=father(y);
}
bool sameset(int x,int y){
    return father(x)==father(y);
}
bool isroot(int x){
    return f[x]==x;
}
void dfs1(int p,int fa,int dep)
{
	ff[p] = fa;
	d[p] = dep;
	size[p] = 1;
	for(register int i = first[p];i;i = pre[i])
		if(to[i] ^ fa)
		{
			dfs1(to[i],p,dep + 1);
			size[p] += size[to[i]];
			if(!son[p] || size[to[i]] > size[son[p]])
				son[p] = to[i];
		}
}
void dfs2(int p,int t)
{
	id[p] = ++dfn_tot;
	rk[dfn_tot] = p;
	top[p] = t;
	if(!son[p])
		return ;
	dfs2(son[p],t);
	for(register int i = first[p];i;i = pre[i])
		if(to[i] ^ ff[p] && to[i] ^ son[p])
			dfs2(to[i],to[i]);
}

int answer(int x,int y)
{
	int ans = 0x3f3f3f3f;
	while(top[x] ^ top[y])
		if(d[top[x]] > d[top[y]])
			ans = min(ans,query(id[top[x]],id[x])),x = ff[top[x]];
		else
			ans = min(ans,query(id[top[y]],id[y])),y = ff[top[y]];
	if(d[x] > d[y])
		swap(x,y);
	ans = min(ans,query(id[x] + 1,id[y]));
	return ans;
}

inline int choose(int x){
    if(d[to[x<<1]]>d[to[(x<<1)-1]])return to[x<<1];
    return to[(x<<1)-1];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++){
        if(!sameset(e[i].u,e[i].v)){
            merge(e[i].u,e[i].v);
            add(e[i].u,e[i].v,e[i].w);
            add(e[i].v,e[i].u,e[i].w);
        }
    }
    for(int i=1;i<=n;i++){
        if(isroot(i))dfs1(i,0,1),dfs2(i,i);
    }
    for(int i=1;i<n;i++)
    a[choose(i)]=val[i<<1];

    for(int i=1;i<=n;i++)st[i][0]=a[rk[i]];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++)
        st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
    }
    scanf("%d",&q);
    int t1,t2;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&t1,&t2);
        if(!sameset(t1,t2))printf("-1\n");
        else printf("%d\n",answer(t1,t2));   
    }
    return 0;
}