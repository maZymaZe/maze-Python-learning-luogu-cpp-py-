class Solution {
public:
    int n,m;
    const int dx[4]={1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        if(matrix.size()==0)return ans;
        n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        queue<int> qx,qy;
        for(int i=0;i<m;i++){
            qx.push(0),qy.push(i);
            v[0][i] =1;
        }
        for(int i=1;i<n;i++){
            qx.push(i),qy.push(0);
            v[i][0]=1;
        }
        while(!qx.empty()){
            int x=qx.front(),y=qy.front();
            qx.pop(),qy.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&!v[nx][ny]&&matrix[nx][ny]>=matrix[x][y]){
                    v[nx][ny]=1;
                    qx.push(nx),qy.push(ny);
                }
            }
        }
        for(int i=0;i<m;i++){
            qx.push(n-1),qy.push(i);
            if(v[n-1][i]==1)ans.push_back({n-1,i});
            v[n-1][i] =2;
        }
        for(int i=0;i<n-1;i++){
            qx.push(i),qy.push(m-1);
            if(v[i][m-1]==1)ans.push_back({i,m-1});
            v[i][m-1]=2;
        }
        while(!qx.empty()){
            int x=qx.front(),y=qy.front();
            qx.pop(),qy.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&v[nx][ny]!=2&&matrix[nx][ny]>=matrix[x][y]){
                    if(v[nx][ny]==1)ans.push_back({nx,ny});
                    v[nx][ny]=2;
                    qx.push(nx),qy.push(ny);
                }
            }
        }
        return ans;
    }
};