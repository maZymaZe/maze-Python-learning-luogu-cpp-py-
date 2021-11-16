class Solution {
public:
    int c=0;
    int ans,n,m;
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int x,int y){
        c++;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m){
                if(!vis[nx][ny]&&grid[nx][ny])dfs(grid,vis,nx,ny);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ans=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    c=0;
                    dfs(grid,vis,i,j);   
                    ans=max(ans,c); 
                }
            }
        }
        return ans;
    }
};