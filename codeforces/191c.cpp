#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int NMAX=1e5+10;
int fa[NMAX],ans[NMAX],f[NMAX],vis[NMAX];
int n,k;
struct EDGE{
    int v,id;
};
vector<EDGE> edges[NMAX];
vector<int> fo[NMAX];
int ff(int x){
    if(fa[x]==x)return x;
    return fa[x]=ff(fa[x]);
}
void tarjan(int x){
    fa[x]=x,vis[x]=1;
    for(int i:fo[x]){
        f[x]++;
        if(vis[i])f[ff(i)]-=2;
    }
    for(EDGE &i:edges[x]){
        if(!vis[i.v]){
            tarjan(i.v);
            f[x]+=ans[i.id]=f[i.v];
            fa[ff(i.v)]=x;
        }
    }
}
int main(){
    int t1,t2;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&t1,&t2);
        edges[t1].push_back({t2,i});
        edges[t2].push_back({t1,i});
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&t1,&t2);
        if(t1!=t2){
            fo[t1].push_back(t2);
            fo[t2].push_back(t1);
        }
        
    }
    tarjan(1);
    for(int i=1;i<n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}