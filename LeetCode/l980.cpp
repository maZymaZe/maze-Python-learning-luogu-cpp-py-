int n,m,bx,by,cnt=2,sx,sy,ans;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        cnt=2,ans=0;
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)cnt++;
                if(grid[i][j]==1)bx=i,by=j;
                if(grid[i][j]==2)sx=i,sy=j;
            }
        }
        grid[bx][by]=-1;
        dfs(bx,by,1,grid);
        return ans;
    }
    void dfs(int x,int y,int s,vector<vector<int>>& grid){
        if(x==sx&&y==sy&&s==cnt){
            ans++;return;
        }
        if(s<cnt){
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<m){
                    if(grid[x+dx[i]][y+dy[i]]!=-1){
                        grid[x+dx[i]][y+dy[i]]=-1;
                        dfs(x+dx[i],y+dy[i],s+1,grid);
                        grid[x+dx[i]][y+dy[i]]=0;
                    }
                }
            }
        }
    }
    
};