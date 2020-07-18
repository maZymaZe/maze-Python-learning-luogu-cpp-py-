struct ND{
    int x,y,m;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        queue<ND> q;
        int ma=0,l1,l2;
        l1=grid.size();
        if(l1==0)return -1;
        l2=grid[0].size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            ND t=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int px=t.x+dx[i],py=t.y+dy[i];
                if(px>=0&&py>=0&&px<l1&&py<l2&&grid[px][py]==1){
                    grid[px][py]=2;
                    q.push({px,py,t.m+1});
                    ma=max(ma,t.m+1);
                }
            }
        }
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        } 
        return ma;   
    }
};