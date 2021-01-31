class Solution {
public:
    vector<vector<int>> ans;
    int n,m,f=0;
    void dfs(vector<vector<int>> &mp,int x,int y){
        if(x==n-1&&y==m-1){
            f=1;
            return;
        }
        if(x+1<n&&!mp[x+1][y]){
            ans.push_back({x+1,y});
            dfs(mp,x+1,y);
            if(f)return;
            mp[x+1][y]=1;
            ans.pop_back();

        }
        if(f)return;
        if(y+1<m&&!mp[x][y+1]){
            ans.push_back({x,y+1});
            dfs(mp,x,y+1);
            if(f)return;
            mp[x][y+1]=1;
            ans.pop_back();
        }
    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        if(n==0)return ans;
        m=obstacleGrid[0].size();
        if(m==0)return ans;
        if(obstacleGrid[0][0]||obstacleGrid[n-1][m-1])return ans;
        ans.push_back({0,0});
        dfs(obstacleGrid,0,0);
        if(!f)ans.clear();
        return ans;
    }
};