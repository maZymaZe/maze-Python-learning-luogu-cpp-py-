#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int NMAX=2e5+10;
vector<int> subtree[NMAX];
int n,q,t,sz[NMAX],ls[NMAX],p=0,bg[NMAX],s;
void dfs(int x){
    sz[x]=1;
    bg[x]=++p;
    ls[p]=x;
    for(int i=0;i<subtree[x].size();i++){
        dfs(subtree[x][i]);
        sz[x]+=sz[subtree[x][i]];
    }
    
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++){
        scanf("%d",&t);
        subtree[t].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&s,&t);
        if(t>sz[s])printf("-1\n");
        else printf("%d\n",ls[bg[s]+t-1]);
    }
    return 0;
}