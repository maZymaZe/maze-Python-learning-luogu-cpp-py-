#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int mp[1503][1503]={0},m,n,v[1503][1503][3]={0},ans;
int dx[5]={0,0,1,0,-1},dy[5]={0,1,0,-1,0},sx,sy;
void dfs(int x,int y,int px,int py){
    if(v[px][py][2]&&(v[px][py][0]!=x||v[px][py][1]!=y)){
        ans=1;
        return;
    } 
    if(v[px][py][2]&&v[px][py][0]==x&&v[px][py][1]==y)return;
    v[px][py][0]=x;v[px][py][1]=y;v[px][py][2]=1;
   
    register int nx,ny;
    for(int i=1;i<=4;i++){
        nx=(px+dx[i]+n)%n;ny=(py+dy[i]+m)%m;
        if(mp[nx][ny]){
            dfs(x+dx[i],y+dy[i],nx,ny);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    register char c;
    while(cin>>n>>m){
        ans=0;
        memset(mp,0,sizeof(mp));
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c;
                if(c=='.')mp[i][j]=1;
                if(c=='S')mp[i][j]=1,sx=i,sy=j;
            }
        }
        dfs(sx,sy,sx,sy);
        if(ans==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}