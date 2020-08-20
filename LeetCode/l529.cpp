struct pr{
    int x,y;
};
const int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1};
class Solution {
public:
    
    int n,m;
    char f(vector<vector<char>>& board,int x,int y){
        if(board[x][y]=='M')return 'X';
        int cnt=0;
        for(int i=0;i<8;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]=='M'){
                cnt++;
            }
        }
        if(cnt==0)return 'B';
        return cnt+'0';
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n=board.size(),m=board[0].size();
        queue<pr> q;
        int vis[52][52]={0};
        q.push({click[0],click[1]});
        vis[click[0]][click[1]]=1;
        while(!q.empty()){
            pr t=q.front();q.pop();
            board[t.x][t.y]=f(board,t.x,t.y);
            if(board[t.x][t.y]=='B'){
                 for(int i=0;i<8;i++){
                    int nx=t.x+dx[i],ny=t.y+dy[i];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]==0){
                        q.push({nx,ny});vis[nx][ny]=1;
                    }
                }
            }
        }
        return board;
    }
};