struct pr{
    int x,y;
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(!board.size())return;
        int n=board.size(),m=board[0].size();
        const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
        queue<pr> q;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0]='F';
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                board[i][m-1]='F';
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[n-1][i]=='O'){
                board[n-1][i]='F';
                q.push({n-1,i});
            }
            if(board[0][i]=='O'){
                board[0][i]='F';
                q.push({0,i});
            }
        }
        while(!q.empty()){
            pr t=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=t.x+dx[i],ny=t.y+dy[i];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&board[nx][ny]=='O'){
                    board[nx][ny]='F';
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='F')board[i][j]='O';
            }
        }
    }
};