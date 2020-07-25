const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n,m;
int dfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int x,int y){
    if(vis[x][y])return vis[x][y];
    vis[x][y]++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&matrix[x][y]<matrix[nx][ny]){
            vis[x][y]=max(dfs(matrix,vis,nx,ny)+1,vis[x][y]);
        }
    }
    return vis[x][y];
}
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        n=matrix.size(),m=matrix[0].size();
        vector<vector<int> > vis(n,vector<int>(m));
        int ans=0;  
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(matrix,vis,i,j));
            }
        }
        return ans;
    }
};