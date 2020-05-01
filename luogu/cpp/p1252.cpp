#include<cstdio>
#include<algorithm>
using namespace std;
int n,h[6003],a[6003],f[6003],bos=0,t1,t2,v[6003],dp[6003],ans=-2147483647;
struct edge{
    int u,v,nx;
}e[6003];
int dfs(int x){
    if(v[x]==1)return dp[x];
    v[x]=1;
    int c1=a[x],c2=0;
    for(int i=h[x];i;i =e[i].nx){
        c2+=max(0,dfs(e[i].v));
        for(int j=h[e[i].v];j;j=e[j].nx){
            c1+=max(0,dfs(e[j].v));
        }
    }
    ans=max(ans,c1);
    ans=max(ans,c2);
    return dp[x]=max(c1,c2);

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        bos^=i;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&t1,&t2);
        bos^=t1;
        e[i].u=t2;e[i].v=t1;e[i].nx=h[t2];
        h[t2]=i;
    }
    dfs(bos);
    printf("%d",ans);
    return 0;
}