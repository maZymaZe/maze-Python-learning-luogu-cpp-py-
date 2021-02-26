class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        const int dx[4]={0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int n2=n*n,x=0,y=0,stat=0;
        for(int i=1;i<=n2;i++){
            ans[x][y]=i;
            int nx=x+dx[stat],ny=y+dy[stat];
            if(nx>=0&&ny>=0&&nx<n&&ny<n&&ans[nx][ny]==0){
                x=nx,y=ny;
            }else{
                stat=(stat+1)%4;
                nx=x+dx[stat],ny=y+dy[stat];
                x=nx,y=ny;
            }
        }
        return ans;
    }
};