#include<cstdio>
int n,m,t,mp[101][201],cnt=0;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void f(int x,int y){
    mp[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=n&&ny<=m&&mp[nx][ny])f(nx,ny);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&t);
            if(t)mp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(mp[i][j]==1){
                cnt++;
                f(i,j);
            }
        }
    }
    printf("%d",cnt);
    return 0;
}