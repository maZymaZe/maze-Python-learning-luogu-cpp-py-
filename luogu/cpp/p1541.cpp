#include<cstdio>
int g[400],n,m,c[5],t,dp[41][41][41][41],ans;
int dfs(int x,int y ,int z,int w){
    if(dp[x][y][z][w])return dp[x][y][z][w];
    int mx=0,mt;
    if(x<c[1]){
        mt=dfs(x+1,y,z,w);
        if(mt>mx)mx=mt;
    }
    if(y<c[2]){
        mt=dfs(x,y+1,z,w);
        if(mt>mx)mx=mt;
    }
    if(z<c[3]){
        mt=dfs(x,y,z+1,w);
        if(mt>mx)mx=mt;
    }
    if(w<c[4]){
        mt=dfs(x,y,z,w+1);
        if(mt>mx)mx=mt;
    }
    return dp[x][y][z][w]=mx+g[1+(c[1]-(x))+(c[2]-y)*2+(c[3]-z)*3+(c[4]-w)*4];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&g[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&t);
        c[t]++;
    }
    dp[c[1]][c[2]][c[3]][c[4]]=g[1];
    ans=dfs(0,0,0,0);
    printf("%d",ans);
    return 0;
}