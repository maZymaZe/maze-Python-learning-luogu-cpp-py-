class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int cnt=0,n=grid.size(),m=grid[0].size(),x;
        for(int i=0;i<n;i++){
            x=0;
            for(int j=0;j<m;j++){
                if(grid[i][j])cnt++;
                x=max(x,grid[i][j]);
            }
            cnt+=x;
            
        }
        for(int i=0;i<m;i++){
            x=0;
            for(int j=0;j<n;j++){
                x=max(x,grid[j][i]);
            }
            cnt+=x;
        }
        return cnt;
    }
};