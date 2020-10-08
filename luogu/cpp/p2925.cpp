#include<cstdio>
int mp[102][102],n,m,ans,nx,ny;
const int dx[4]={-1,1,0,0},dy[4]={0,0,1,-1};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    int x=1,y=1;
    while(1){
        ans+=mp[x][y];
        mp[x][y]=0;
        if(x==n&&y==m)break;
        int ma=0;
        for(int i=0;i<4;i++){
            if(mp[x+dx[i]][y+dy[i]]>ma){
                ma=mp[x+dx[i]][y+dy[i]];
                nx=x+dx[i],ny=y+dy[i];
            }
        }
        x=nx,y=ny;
    }
    printf("%d\n",ans);
    return 0;
}