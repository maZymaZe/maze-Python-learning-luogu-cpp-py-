class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int x=0,y=0,n=matrix.size();
        vector<int> ans;
        if(!n)return ans;
        int m=matrix[0].size(),stat=0,dx[2]={-1,1},dy[2]={1,-1};
        while(1){
            ans.push_back(matrix[x][y]);
            if(x==n-1&&y==m-1)break;
            int nx=x+dx[stat],ny=y+dy[stat];
            if(nx>=0&&ny>=0&&nx<n&&ny<m){
                x=nx,y=ny;
            }else{
                if(stat==0){
                    if(y+1<m)y++;
                    else x++;
                }else{
                    if(x+1<n)x++;
                    else y++;
                }
                stat^=1;
            }
        }
        return ans;
    }
};