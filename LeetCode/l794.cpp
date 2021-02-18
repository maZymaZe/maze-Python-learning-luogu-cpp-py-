class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int c1=0,c2=0;
        for(int i=0;i<3; i++)
        for(int j=0;j<3; j++)
        if(board[i][j]=='X')c1++;
        else if(board[i][j]=='O')c2++;
        bool w1=cw('X',board),w2=cw('O',board);
        if(c1==c2+1&&w1&&!w2)return true;
        if(c1==c2&&w2&&!w1)return true;
        if((c1==c2||c1==c2+1)&&!w1&&!w2)return true;
        return false;
    }
    bool cw(char c, vector<string>& board) {
        for(int i=0;i<3;i++){
            if(board[i][0]==c&&board[i][1]==c&&board[i][2]==c)return true;
            if(board[0][i]==c&&board[1][i]==c&&board[2][i]==c)return true;
        }
        if(board[0][0]==c&&board[1][1]==c&&board[2][2]==c)return true;
        if(board[0][2]==c&&board[1][1]==c&&board[2][0]==c)return true;
        return false;
    }
};