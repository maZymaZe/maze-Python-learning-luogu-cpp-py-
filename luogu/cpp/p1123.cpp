#include<cstdio>
#include<cstring>
int max(int a,int b){ return a > b ? a : b;}
int v[8][8],n,m,T,mp[8][8],ans;
int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={1,0,-1,1,-1,1,0,-1};
bool ok(int x,int y){
    for(int i=0;i<8;i++)if(v[x+dx[i]][y+dy[i]])return false;
    return true;
}
void dfs(int x,int y,int tot){
    if(y>m){
        dfs(x+1,1,tot);
        return;
    }
    if(x>n){ans=max(ans,tot);return;}
    dfs(x,y+1,tot);
    if(ok(x,y)){
        v[x][y]=1;
        dfs(x,y+1,tot+mp[x][y]);
        v[x][y]=0;
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        ans=0;
        memset(v,0,sizeof(v));
        memset(mp,0,sizeof(mp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        dfs(1,1,0);
        printf("%d\n",ans);
    }
    return 0;
}