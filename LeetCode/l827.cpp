class Solution {
public:
    int n,m,cnt=0;
    int used[51][51],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},gp[51][51],p=0,uu[2501];
    void cunt(vector<vector<int>>&grid,int x,int y){
        cnt++;
        used[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!used[nx][ny]&&grid[nx][ny]){
                cunt(grid,nx,ny);
            }
        }
    }
    void fll(vector<vector<int>>&grid,int x,int y){
        grid[x][y] =cnt;
        gp[x][y]=p;
        used[x][y]=1;
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&ny>=0&&nx<n&&ny<m&&!used[nx][ny]&&grid[nx][ny]){
                fll(grid,nx,ny);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    cnt=0;p++;
                    memset(used,0,sizeof(used));
                    cunt(grid,i,j);
                    memset(used,0,sizeof(used));
                    fll(grid,i,j);
                }
            }
        }
        int ans=0,f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]){
                   f=1;
                   int c=1;
                   if(i-1>=0&&!uu[gp[i-1][j]])c+=grid[i-1][j],uu[gp[i-1][j]]=1;
                   if(j-1>=0&&!uu[gp[i][j-1]])c+=grid[i][j-1],uu[gp[i][j-1]]=1;
                   if(i+1<n&&!uu[gp[i+1][j]])c+=grid[i+1][j],uu[gp[i+1][j]]=1;
                   if(j+1<m&&!uu[gp[i][j+1]])c+=grid[i][j+1],uu[gp[i][j+1]]=1;
                   ans=max(ans,c);
                   if(i-1>=0)uu[gp[i-1][j]]=0;
                   if(j-1>=0)uu[gp[i][j-1]]=0;
                   if(i+1<n)uu[gp[i+1][j]]=0;
                   if(j+1<m)uu[gp[i][j+1]]=0;
                }
            }
        }
        if(!f)return n*m;
        return ans;
    }
};