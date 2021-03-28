#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int NMAX=1e3+10;
int n,mp[NMAX][NMAX],vis[NMAX][NMAX],x1,y1,x2,y2,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
queue<int> qx,qy;
int main(){
    scanf("%d",&n);
    memset(vis,0x3f, sizeof(vis));
    memset(mp,-1, sizeof(mp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&mp[i][j]);
        }
    }
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    vis[x1][y1]=0;
    qx.push(x1),qy.push(y1);
    while(!qx.empty()){
        int x=qx.front(),y=qy.front();
        qx.pop(),qy.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>0&&nx<=n&&ny>0&&ny<=n&&mp[nx][ny]==0){
                if(vis[nx][ny]==0x3f3f3f3f){
                    vis[nx][ny]=vis[x][y]+1;
                    qx.push(nx),qy.push(ny);
                    if(nx==x2&&ny==y2){
                        printf("%d\n",vis[nx][ny]);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
 
}