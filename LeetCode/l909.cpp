class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size(),tot;
        tot=n*n;
        vector<int> v(tot+10),answer(tot+10),mpx(tot+10),mpy(tot+10);
        int x=n-1,y=0,f=0;
        for(int i=1;i<=tot; i++){
            mpx[i]=x,mpy[i]=y;
            if(f==0){
                if(y==n-1){
                    x--,f^=1;
                }else y++;
            }else{
                if(y==0)x--,f^=1;
                else y--;
            }
        }
        answer[1]=0;
        v[1]=1;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int h=q.front();
            q.pop();
            for(int i=1;i<=6;i++){
                int nx=h+i;
                if(nx>tot)continue;
                if(board[mpx[nx]][mpy[nx]]==-1){
                    if(!v[nx]){
                        v[nx]=1;
                        q.push(nx);
                        answer[nx]=answer[h]+1;
                    }
                }else{
                    if(!v[board[mpx[nx]][mpy[nx]]]){
                        v[board[mpx[nx]][mpy[nx]]]=1;
                        q.push(board[mpx[nx]][mpy[nx]]);
                        answer[board[mpx[nx]][mpy[nx]]]=answer[h]+1;
                    }
                }
            }
        }
        if(!v[tot])return -1;
        return answer[tot];
    }
};