#include <cstdio>
#include<cstring>
int mp[9][9],a,b,ans=0;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y){
    if(x<1||y<1||x==a||y==b){
        ans++; return;
    }
    mp[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(mp[nx][ny]==0){
            dfs(nx,ny);
            
        }
    }
    mp[x][y]=0;
}
int main() {
    scanf("%d%d",&a,&b);
    for(int i=1;i<a;i++){
        mp[i][0]=1;
        dfs(i,1);
        mp[i][0]=0;
    }
    for(int i=1;i<b;i++){
        mp[0][i]=1;
        dfs(1,i);
        mp[0][i]=0;
    }
    printf("%d",ans);
    return 0;
}